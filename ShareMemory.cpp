#include"ShareMemory.h"


ShareMemory::ShareMemory(){}

ShareMemory::~ShareMemory(){

}

int ShareMemory::createShmId(key_t key,int size){
    /*返回值:成功创建或打开，返回0，否则返回-1*/
    if(size > 0){
        shmId = shmget(key,size,IPC_CREAT|0755);
    }
    else{
        shmId = shmget(key,0,0);
    }
    if(shmId == -1){
        perror("ShareMemory::createShmId Err: ");
        return -1;
    }
    return 0;
}

int ShareMemory::createShmId(std::string path,int size){
    /*返回值：成功创建或打开，返回0，否则返回-1*/
    key_t key = ftok(path.data(),token);
    if(size > 0){
        shmId = shmget(key,size,IPC_CREAT|0755);
    }
    else{
        shmId = shmget(key,0,0);
    }
    if(shmId == -1){
        perror("ShareMemory::createShmId Err: ");
        return -1;
    }
    return 0;
}


void* ShareMemory::mapShm(){
    /*返回值：正常返回指向shm的指针，异常返回nullptr*/
    shmAddr = shmat(shmId,nullptr,0);
    if(shmAddr == (void*)-1){
        perror("ShareMemory::mapShm Err: ");
        return nullptr;
    }
    return shmAddr;
}

int ShareMemory::unmapShm(){
    /*返回值：正常返回0，异常返回-1*/
    if(shmAddr == (void*)-1){
        fprintf(stderr,"ShareMemory::unmapShm error:shmAddr == (void*)-1\n");
        return -1;
    }
    int ret = shmdt(shmAddr);
    if(ret < 0){
        perror("ShareMemory::unmapShm shmdt Err:");
        return -1;
    }
    return 0;
}


