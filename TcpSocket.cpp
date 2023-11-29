#include "TcpSocket.h"

TcpSocket::TcpSocket()
{
}

TcpSocket::TcpSocket(int connfd) : connfd(connfd) {}

TcpSocket::~TcpSocket()
{
    if (connfd > 0)
    {
        close(connfd);
    }
}

int TcpSocket::connectToHost(std::string ip, unsigned int port, unsigned int waitSeconds)
{
    // 参数检查
    if (port <= 0 || port > 65535 || waitSeconds < 0)
    {
        printf("connectToHost parament error");
        return -1;
    }
    connfd = socket(AF_INET, SOCK_STREAM, 0);
    if (connfd < 0)
    {
        perror("TcpSocket::connectToHost socket error");
        return -1;
    }
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    serverAddr.sin_addr.s_addr = inet_addr(ip.data());
    int ret = connectTimeout(&serverAddr, waitSeconds);
    if (ret == -1)
    {
        return ret;
    }
    return 0;
}

int TcpSocket::sendMsg(std::string sendMsg, unsigned int waitSeconds)
{
    /*正常返回0，超时或者异常返回-1，并设置了errno，数据发送失败返回已发送的字节数*/

    /*思路:先检测参数，再考虑写是否超时，将stirng类参数转换为const char*型字符串，再封装包头，发送数据*/
    int ret = 0;
    if (connfd < 0)
    {
        fprintf(stderr, "TcpSocket::sendMsg connfd is not valid\n");
        return -1;
    }
    if (waitSeconds > 0)
    {
        ret = writeTimeout(waitSeconds);
        if (ret == -1)
        {
            return -1;
        }
    }

    // 封装包头
    int sendDataLen = sendMsg.length();
    const char *sendData = sendMsg.data();
    int packageLen = sendDataLen + 4;
    char *package = new char[packageLen];
    int packageHead = htonl(sendDataLen);
    memcpy(package, &packageHead, 4);
    memcpy(package + 4, sendData, sendDataLen);

    // 发送数据
    int writed = writen(package, packageLen);
    // 释放内存
    if (package != nullptr)
    {
        delete[] package;
        package = nullptr;
    }
    // 返回
    if (writed != packageLen)
    {
        return writed;
    }
    return 0;
}

int TcpSocket::recvMsg(std::string &recvMsg, unsigned int waitSeconds)
{
    /*返回值：正常返回接收的字节数，客户端退出返回0，异常返回-1*/
    /*思路：先检查connfd的合法性，再检测超时，再读取包头，再读取数据*/
    int ret = 0;
    if (connfd < 0)
    {
        fprintf(stderr, "connfd is invalid\n");
        return -1;
    }
    if (waitSeconds > 0)
    {
        ret = readTimeout(waitSeconds);
        if (ret == -1)
        {
            return -1;
        }
    }
    /*读取包头*/
    int packageHead;
    ret = readn(&packageHead, 4);
    if (ret == 0)
    {
        // 说明客户端退出
        return 0;
    }
    else if (ret != 4)
    {
        // 存在异常
        return -1;
    }
    int dataLen = ntohl(packageHead);
    /*读取数据*/
    char *data = new char[dataLen];
    ret = readn(data, dataLen);
    if (ret > 0)
    {
        recvMsg = std::string(data,ret);
    }
    if (data != nullptr)
    {
        delete data;
        data = nullptr;
    }
    return ret;
}

int TcpSocket::connectTimeout(const struct sockaddr_in *addr, unsigned int waitSeconds)
{
    /*先将connfd设置为非阻塞，通过select检查connfd的写缓冲区，当事件触发时，通过getsockopt检查是否connect成功*/
    socklen_t addrlen = sizeof(struct sockaddr_in);
    if (waitSeconds > 0)
    {
        setNonBlock();
    }
    int ret = connect(connfd, (struct sockaddr *)addr, addrlen);
    /*
    It is possible to select(2) or poll(2) for completion by selecting the socket for writing.  After select(2) indicates writability,
    use getsockopt(2) to read the SO_ER‐ROR  option  at  level  SOL_SOCKET to determine whether connect() completed successfully
     (SO_ERROR is zero) or unsuccessfully (SO_ERROR is one of the usual error codes listed here, explaining the reason for the failure).
    */
    fd_set wrset;
    FD_ZERO(&wrset);
    FD_SET(connfd, &wrset);
    struct timeval timeoutStruct = {waitSeconds, 0};
    if (ret < 0 && errno == EINPROGRESS)
    {
        do
        {
            ret = select(connfd + 1, nullptr, &wrset, nullptr, &timeoutStruct);
        } while (ret < 0 && errno == EINTR);

        if (ret == 0)
        {
            /*select 超时，等待后面将文件描述符设置为非阻塞后一起返回*/
            ret = -1;
            errno = ETIMEDOUT;
            perror("TcpSocket::connectTimeout select timeout");
        }
        else if (ret == 1)
        {
            int err;
            socklen_t optlen = sizeof(err);
            ret = getsockopt(connfd, SOL_SOCKET, SO_ERROR, &err, &optlen);
            if (ret == -1)
            {
                perror("TcpSocket::connectTimeout getsockopt error");
            }
            else if (err == 0)
            {
                ret = 0;
            }
            else
            {
                errno = err;
                ret = -1;
                perror("TcpSocket::connectTimeout connect error");
            }
        }
    }
    else if (ret == -1)
    {
        perror("TcpSocket::connectTimeout connect error");
        return -1;
    }
    if (waitSeconds > 0)
    {
        setBlock();
    }
    return ret;
}

int TcpSocket::setBlock()
{
    int ret = 0;
    /*fcntl  F_GET 错误返回-1 */
    int flags = fcntl(connfd, F_GETFL);
    if (flags == -1)
    {
        perror("fcntl error");
        return -1;
    }
    flags &= ~O_NONBLOCK;
    /*fcntl  F_SET 错误返回-1 */
    ret = fcntl(connfd, F_SETFL, flags);
    if (ret != 0)
    {
        perror("setBlock fcntl F_SETFL error");
        return -1;
    }
    return ret;
}

int TcpSocket::setNonBlock()
{
    int ret = 0;
    int flags = fcntl(connfd, F_GETFL);
    if (flags == -1)
    {
        perror("fcntl error");
        return -1;
    }
    flags |= O_NONBLOCK;
    ret = fcntl(connfd, F_SETFL, flags);
    if (ret != 0)
    {
        perror("setBlock fcntl F_SETFL error");
        return -1;
    }
    return ret;
}

int TcpSocket::writeTimeout(unsigned int waitSeconds)
{
    /*思路：先通过select检测写缓冲区是否可写，如可写直接调用*/
    fd_set wrset;
    FD_ZERO(&wrset);
    FD_SET(connfd, &wrset);
    struct timeval timeout = {waitSeconds, 0};
    int ret;
    do
    {
        ret = select(connfd + 1, nullptr, &wrset, nullptr, &timeout);
    } while (ret == -1 && errno == EINTR);
    if (ret == 0)
    {
        /*超时*/
        errno = ETIMEDOUT;
        perror("TcpSocket::writeTimeout select timeout\n");
        return -1;
    }
    else if (ret == 1)
    {
        /*规定时间内检测到写缓冲区可用*/
        return 0;
    }
    else
    {
        printf("TcpSocket::writeTimeout select error\n");
        return -1;
    }
}

int TcpSocket::writen(const char *data, unsigned int dataLen)
{
    /*返回值说明：正常返回dataLen,异常返回-1*/
    unsigned int nleft = dataLen;
    unsigned int nwrite = 0;
    int ret = 0;
    while (nleft > 0)
    {
        nwrite = write(connfd, data, nleft);
        if (nwrite == -1 && errno == EINTR)
        {
            continue;
        }
        else if (nwrite > 0)
        {
            nleft -= nwrite;
            data += nwrite;
        }
        else
        {
            perror("TcpSocket::writen Error:");
            // return dataLen - nleft;
            return -1;
        }
    }
    return dataLen;
}

int TcpSocket::readTimeout(unsigned int waitSeconds)
{
    int ret = 0;
    fd_set rdset;
    FD_ZERO(&rdset);
    FD_SET(connfd, &rdset);
    struct timeval timeout = {waitSeconds, 0};
    do
    {
        ret = select(connfd + 1, &rdset, nullptr, nullptr, &timeout);
    } while (ret == -1 && errno == EINTR);
    if (ret == 0)
    {
        errno == ETIMEDOUT;
        return -1;
    }
    else if (ret == 1)
    {
        return 0;
    }
    else
    {
        perror("TcpSocket::readTimeout select error:");
        return -1;
    }
}

int TcpSocket::readn(void *data, unsigned int dataLen)
{
    /*异常返回-1，客户端退出返回0，正常返回dataLen*/
    char *dataptr = (char *)data;
    int nread = 0;
    int nleft = dataLen;
    while (nleft > 0)
    {
        nread = read(connfd, dataptr, dataLen);
        if (nread == -1 && errno == EINTR)
        {
            continue;
        }
        else if (nread > 0)
        {
            nleft -= nread;
            dataptr += nread;
        }
        else if (nread == 0)
        {
            return 0;
        }
        else
        {
            perror("TcpSocket::readn read error");
            // return dataLen - nleft;
            return -1;
        }
    }
    return dataLen;
}