#pragma once
#include"ShareMemory.h"

enum ShmMsgStatus{SPARESPACE=-1,BUSYSPACE};

// struct ShmMsg{
// public:
//     ShmMsg():status(SPARESPACE),seckeyId(0),clientId(std::string(12,'\0')),serverId(std::string(12,'\0')),seckey(std::string(128,'\0')){}
//     ShmMsg(int status,int seckeyId,std::string clientId,std::string serverId,std::string seckey):status(status),seckeyId(seckeyId),clientId(clientId),serverId(serverId),seckey(seckey){}
//     int status;
//     int seckeyId;
//     std::string clientId;
//     std::string serverId;
//     std::string seckey; 
// };
/*务必记住共享内存中不可以存储指针或者引用以及stl中的容器*/

struct ShmMsg{
public:
    int status;
    int seckeyId;
    char clientId[12];
    char serverId[12];
    char seckey[32];
};


class SecKeyShm:public ShareMemory{
public:
    SecKeyShm();
    ~SecKeyShm();
    int createSecKeyShm(key_t key,int num);
    int createSecKeyShm(std::string path,int num);
    int writeShm(ShmMsg& msg);
    int readShm(std::string clientId,std::string serverId,ShmMsg& shmMsg);
    void printShm();
    int initeShm();
private:
    ShmMsg msg;
    int maxNode;
};



