#pragma once
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <stdio.h>
#include <iostream>
#include <arpa/inet.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/select.h>
#include <sys/time.h>
#include <string.h>
class TcpSocket
{
public:
    TcpSocket();
    TcpSocket(int connfd);
    ~TcpSocket();
    int connectToHost(std::string ip, unsigned int port, unsigned int waitSeconds);
    int sendMsg(std::string sendMsg, unsigned int waitSeconds);
    int recvMsg(std::string &recvMsg, unsigned int waitSeconds);

private:
    int connectTimeout(const struct sockaddr_in *addr, unsigned int waitSeconds);
    int setBlock();
    int setNonBlock();
    int writeTimeout(unsigned int waitSeconds);
    int writen(const char *data, unsigned int dataLen);
    int readTimeout(unsigned int waitSeconds);
    int readn(void *data, unsigned int dataLen);
    int connfd;
};