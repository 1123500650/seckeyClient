#pragma once
#include<iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include<string.h>
const int token = 0x12;

class ShareMemory{
protected:
    ShareMemory();
    ~ShareMemory();
    int createShmId(key_t key,int size);
    int createShmId(std::string path,int size);
    void* mapShm();
    int unmapShm();
    int shmId;
private:
    void* shmAddr;    
};
