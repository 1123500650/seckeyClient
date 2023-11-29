#include "ClientWorking.h"

ClientWorking::ClientWorking()
{

    JsonString json;
    readJsonFile = json.readFromJson(clientInfo);
    if (!readJsonFile)
    {
        std::cerr << "json.readFromJson Error " << std::endl;
    }
    else
    {
        std::cout << "read jsonFile Successfully" << std::endl;
    }
}

ClientWorking::~ClientWorking()
{
}

void ClientWorking::seckeyNegotiate()
{
    /*
    1.生成公钥并对公钥进行签名
    2.组织请求报文
    3.报文序列化
    4.链接服务器，发送数据
    5.等待服务器响应
    6.报文反序列化
    7.查看status
    8.获得秘钥
    */
    // 生成公钥，
    RSAencrypt rsa;
    rsa.createRSA();
    bool ret = rsa.saveRSAToFile("rsaPublic.pem", "rsaPrivate.pem");
    if (!ret)
    {
        std::cerr << "rsa.saveRSAToFile Error" << std::endl;
        return;
    }
    // bool ret = rsa.createRSA("rsaPublic.pem", "rsaPrivate.pem");
    //  从文件中读取公钥
    std::string rsaPublicKey;
    std::ifstream ifs("rsaPublic.pem");
    std::stringstream str;
    str << ifs.rdbuf();
    rsaPublicKey = str.str();
    ifs.close();
    // 对公钥进行签名
    std::string sign;
    ret = rsa.RSAPrivateSign(rsaPublicKey, sign);
    if (!ret)
    {
        std::cerr << "rsa.RSAPrivateSign Error" << std::endl;
        return;
    }
    // 组织请求报文
    RequestMsg clientMsg;
    clientMsg.clientId = clientInfo.clientId;
    clientMsg.cmdType = SECKEYNEGOTIATE;
    clientMsg.serverId = clientInfo.serverId;
    clientMsg.data = rsaPublicKey;
    clientMsg.sign = sign;
    // 将请求报文序列化
    BaseFactory *sendFactory = new RequestFactory(clientMsg);
    Codec *sendCodec = sendFactory->createFactory();
    std::string sendPackage;
    sendCodec->msgSeraize(sendPackage);
    if (sendFactory != nullptr)
    {
        delete sendFactory;
        sendFactory = nullptr;
    }
    if (sendCodec != nullptr)
    {
        delete sendCodec;
        sendCodec = nullptr;
    }
    // 向服务器发送请求
    TcpSocket *socket = new TcpSocket;
    int result = socket->connectToHost(clientInfo.serverIp, clientInfo.port, 1);
    if (result != 0)
    {
        if (socket != nullptr)
        {
            delete socket;
            socket = nullptr;
        }
        std::cerr << "ClientWorking::seckeyNegotiate() socket->connectToHost Error" << std::endl;
        return;
    }
    std::cout << "connect to server successfully" << std::endl;
    // 发送报文
    result = socket->sendMsg(sendPackage, 1);
    if (result != 0)
    {
        if (socket != nullptr)
        {
            delete socket;
            socket = nullptr;
        }
        std::cerr << "ClientWorking::seckeyNegotiate() socket->sendMsg(sendPackage,10) Error" << std::endl;
        return;
    }
    // 等待接收报文
    std::string recvPackage;
    result = socket->recvMsg(recvPackage, 1);
    if (result == -1)
    {
        std::cerr << "ClientWorking::seckeyNegotiate() socket->recvMsg(recvPackage,10) Error" << std::endl;
        return;
    }
    else if (result == 0)
    {
        std::cerr << "Server quit" << std::endl;
        return;
    }
    // 将接收到的报文反序列化
    RespondMsg *serverMsg = new RespondMsg;
    BaseFactory *recvFactory = new RespondFactory;
    Codec *recvCodec = recvFactory->createFactory();
    serverMsg = static_cast<RespondMsg *>(recvCodec->msgParse(recvPackage));
    // 查看status
    if (serverMsg->status == STATUS_FAULT)
    {
        std::cout << "seckeyNegotiation Error" << std::endl;
        return;
    }
    // 对秘钥进行解密
    std::string seckey = rsa.RSAPrivateDecrypt(serverMsg->data);
    std::cout << "the seckey is " << seckey << std::endl;
    // 组织ShmMsg
    ShmMsg shmMsg;
    // 清空shmMsg
    memset(&shmMsg, 0x00, sizeof(struct ShmMsg));
    shmMsg.status = BUSYSPACE;
    shmMsg.seckeyId = serverMsg->seckeyid;
    memcpy(shmMsg.clientId, serverMsg->clientId.c_str(), serverMsg->clientId.size());
    memcpy(shmMsg.serverId, serverMsg->serverId.c_str(), serverMsg->serverId.size());
    memcpy(shmMsg.seckey, seckey.c_str(), seckey.size());
    std::cout << "the shmMsg.seckey is " << shmMsg.seckey << std::endl;
    SecKeyShm shm;
    shm.createSecKeyShm(0x1234, 1);
    ret = shm.writeShm(shmMsg);
    if (ret != 0)
    {
        std::cerr << "ClientWorking::seckeyNegotiate seckeyShm->writeShm Error " << std::endl;
    }
    return;
}

void ClientWorking::seckeyValidate()
{
    /*
    1.从.pem中读取私钥
    2.取秘钥作为数据
    3.对数据使用现有的秘钥进行哈希
    4.对哈希后的数据进行签名
    5.组织请求报文
    6.发送数据
    7.等待接收
    8.查看状态位
    */
    RSAencrypt rsa;
    bool ret = rsa.createRSA(nullptr, "rsaPrivate.pem");
    if (!ret)
    {
        std::cerr << "get rsaPrivate.pem Error " << std::endl;
        return;
    }
    ShmMsg shmMsg;
    SecKeyShm shm;
    shm.createSecKeyShm(0x1234, 0);
    int result = shm.readShm(clientInfo.clientId, clientInfo.serverId, shmMsg);
    if (result == -1)
    {
        std::cerr << "ClientWorking::seckeyValidate shm.readShm Error " << std::endl;
        return;
    }
    std::string seckey = shmMsg.seckey;
    std::cout << "the seckey is " << seckey << std::endl;
    // 对秘钥进行哈希
    HashString hash(HashString::USESHA256);
    std::string seckeyHash = hash.getHashResult(seckey.data(), seckey.size());
    std::cout << "the seckeyHash is " << seckeyHash << std::endl;
    // 对哈希的结果进行签名
    std::string seckeyHashSign;
    ret = rsa.RSAPrivateSign(seckeyHash, seckeyHashSign);
    if (!ret)
    {
        std::cerr << "ClientWorking::seckeyValidate rsa.RSAPrivateSign Error " << std::endl;
        return;
    }
    // 阻值发送报文
    RequestMsg sendMsg;
    sendMsg.cmdType = SECKEYVALIDATE;
    sendMsg.clientId = clientInfo.clientId;
    sendMsg.serverId = clientInfo.serverId;
    sendMsg.data = seckeyHash;
    sendMsg.sign = seckeyHashSign;
    // 将数据序列化
    BaseFactory *factory = new RequestFactory(sendMsg);
    Codec *codec = factory->createFactory();
    std::string sendPackage;
    codec->msgSeraize(sendPackage);
    if (factory != nullptr)
    {
        delete factory;
        factory = nullptr;
    }
    if (codec != nullptr)
    {
        delete codec;
        codec = nullptr;
    }
    // 准备socket,向服务器发送数据
    TcpSocket socket;
    result = socket.connectToHost(clientInfo.serverIp, clientInfo.port, 1);
    if (result == -1)
    {
        std::cerr << "ClientWorking::seckeyValidate socket.connectToHost Error " << std::endl;
        return;
    }
    // 发送数据
    result = socket.sendMsg(sendPackage, 10);
    if (result == -1)
    {
        std::cerr << "ClientWorking::seckeyValidate socket.sendMsg Error " << std::endl;
        return;
    }
    // 等待接收数据
    std::string recvPackage;
    result = socket.recvMsg(recvPackage, 10);
    if (result == -1)
    {
        std::cerr << "ClientWorking::seckeyValidate socket.recvMsg Error " << std::endl;
        return;
    }
    // 对接收到的数据进行反序列化
    factory = new RespondFactory();
    codec = factory->createFactory();
    RespondMsg *respondMsg;
    respondMsg = static_cast<RespondMsg *>(codec->msgParse(recvPackage));
    int status = respondMsg->status;
    if (factory != nullptr)
    {
        delete factory;
        factory = nullptr;
    }
    if (codec != nullptr)
    {
        delete codec;
        codec = nullptr;
    }
    if (status == STATUS_NOTEQUAL)
    {
        std::cout << "seckey is not same " << std::endl;
        return;
    }
    else if (status == STATUS_OK)
    {
        std::cout << "seckey is the same " << std::endl;
        return;
    }
    std::cout << "seckeyValidate Wrong " << std::endl;
}

void ClientWorking::seckeyLogout()
{
    /*
    客户端秘钥注销：
    1.从pem文件中读取私钥
    2.从shm中读取现有的秘钥
    3.对秘钥进行哈希作为数据
    4.对数据进行私钥签名
    5.链接服务器
    6.组织发送报文
    */
    RSAencrypt rsa;
    bool ret = rsa.createRSA(nullptr, "rsaPrivate.pem");
    if (!ret)
    {
        std::cerr << "get rsaPrivate.pem Error " << std::endl;
        return;
    }
    ShmMsg shmMsg;
    SecKeyShm shm;
    shm.createSecKeyShm(0x1234, 0);
    int result = shm.readShm(clientInfo.clientId, clientInfo.serverId, shmMsg);
    if (result == -1)
    {
        std::cerr << "ClientWorking::seckeyValidate shm.readShm Error " << std::endl;
        return;
    }
    std::string seckey = shmMsg.seckey;
    std::cout << "the seckey is " << seckey << std::endl;
    // 对秘钥进行哈希
    HashString hash(HashString::USESHA256);
    std::string seckeyHash = hash.getHashResult(seckey.data(), seckey.size());
    std::cout << "the seckeyHash is " << seckeyHash << std::endl;
    // 对哈希的结果进行签名
    std::string seckeyHashSign;
    ret = rsa.RSAPrivateSign(seckeyHash, seckeyHashSign);
    if (!ret)
    {
        std::cerr << "ClientWorking::seckeyValidate rsa.RSAPrivateSign Error " << std::endl;
        return;
    }
    // 阻值发送报文
    RequestMsg sendMsg;
    sendMsg.cmdType = SECKEYLOGOUT;
    sendMsg.clientId = clientInfo.clientId;
    sendMsg.serverId = clientInfo.serverId;
    sendMsg.data = seckeyHash;
    sendMsg.sign = seckeyHashSign;
    // 将数据序列化
    BaseFactory *factory = new RequestFactory(sendMsg);
    Codec *codec = factory->createFactory();
    std::string sendPackage;
    codec->msgSeraize(sendPackage);
    if (factory != nullptr)
    {
        delete factory;
        factory = nullptr;
    }
    if (codec != nullptr)
    {
        delete codec;
        codec = nullptr;
    }
    // 准备socket,向服务器发送数据
    TcpSocket socket;
    result = socket.connectToHost(clientInfo.serverIp, clientInfo.port, 1);
    if (result == -1)
    {
        std::cerr << "ClientWorking::seckeyValidate socket.connectToHost Error " << std::endl;
        return;
    }
    // 发送数据
    result = socket.sendMsg(sendPackage, 10);
    if (result == -1)
    {
        std::cerr << "ClientWorking::seckeyValidate socket.sendMsg Error " << std::endl;
        return;
    }
    // 等待接收数据
    std::string recvPackage;
    result = socket.recvMsg(recvPackage, 10);
    if (result == -1)
    {
        std::cerr << "ClientWorking::seckeyValidate socket.recvMsg Error " << std::endl;
        return;
    }
    // 对接收到的数据进行反序列化
    factory = new RespondFactory();
    codec = factory->createFactory();
    RespondMsg *respondMsg;
    respondMsg = static_cast<RespondMsg *>(codec->msgParse(recvPackage));
    int status = respondMsg->status;
    if (factory != nullptr)
    {
        delete factory;
        factory = nullptr;
    }
    if (codec != nullptr)
    {
        delete codec;
        codec = nullptr;
    }
    if (status == STATUS_OK)
    {
        std::cout << "seckeyLogOut is finished  " << std::endl;
        return;
    }
    std::cout << "seckeyLogOut Wrong " << std::endl;
}