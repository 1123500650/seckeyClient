#include "SecKeyShm.h"

SecKeyShm::SecKeyShm() {}

SecKeyShm::~SecKeyShm() {}

int SecKeyShm::createSecKeyShm(key_t key, int num)
{
    int ret = createShmId(key, sizeof(ShmMsg) * num);
    if (num > 0)
    {
        maxNode = num;
        initeShm();
        return ret;
    }
    else if (num == 0 && ret == 0)
    {
        struct shmid_ds shmInfo;
        ret = shmctl(shmId, IPC_STAT, &shmInfo);
        if (ret == -1)
        {
            perror("SecKeyShm::createSecKeyShm shmctl Err: ");
            return -1;
        }
        maxNode = shmInfo.shm_segsz / sizeof(struct ShmMsg);
    }
    return ret;
}

int SecKeyShm::createSecKeyShm(std::string path, int num)
{
    int ret = createShmId(path, sizeof(ShmMsg) * num);
    if (num > 0)
    {
        maxNode = num;
        initeShm();
        return ret;
    }
    else if (num == 0 && ret == 0)
    {
        struct shmid_ds shmInfo;
        ret = shmctl(shmId, IPC_STAT, &shmInfo);
        if (ret == -1)
        {
            perror("SecKeyShm::createSecKeyShm shmctl Err: ");
            return -1;
        }
        maxNode = shmInfo.shm_segsz / sizeof(struct ShmMsg);
    }
    return ret;
}

int SecKeyShm::readShm(std::string clientId, std::string serverId, ShmMsg &shmMsg)
{
    ShmMsg *shmAddr = (ShmMsg *)mapShm();
    if (shmAddr == nullptr)
    {
        return -1;
    }
    int i;
    for (i = 0; i < maxNode; i++)
    {
        if (strcmp(shmAddr->clientId, clientId.c_str()) == 0 && strcmp(shmAddr->serverId, serverId.c_str()) == 0)
        {
            break;
        }
        shmAddr++;
    }
    if (i == maxNode)
    {
        fprintf(stderr, "there is no corresponding node in shm\n");
        return -1;
    }
    memcpy(&shmMsg, shmAddr, sizeof(struct ShmMsg));
    int ret = unmapShm();
    if (ret == -1)
    {
        fprintf(stderr, "SecKeyShm::readShm unmapShm() Err\n");
        return -1;
    }
    return 0;
}

int SecKeyShm::writeShm(ShmMsg &msg)
{
    ShmMsg *shmAddr = (ShmMsg *)mapShm();
    if (shmAddr == nullptr)
    {
        return -1;
    }
    int targetIndex;
    ShmMsg *targetAddr = shmAddr;
    for (targetIndex = 0; targetIndex < maxNode; ++targetIndex)
    {
        if (strcmp(targetAddr->clientId, msg.clientId) == 0 && strcmp(targetAddr->serverId, msg.serverId) == 0)
        {
            memcpy(targetAddr, &msg, sizeof(struct ShmMsg));
            break;
        }
        ++targetAddr;
    }
    if (targetIndex != maxNode)
    {
        return 0;
    }
    targetAddr = shmAddr;
    for (targetIndex = 0; targetIndex < maxNode; ++targetIndex)
    {
        if (targetAddr->status == SPARESPACE)
        {
            memcpy(targetAddr, &msg, sizeof(struct ShmMsg));
            break;
        }
        ++targetAddr;
    }
    if (targetIndex == maxNode)
    {
        fprintf(stderr, "there is no spare space in shm\n");
        return -1;
    }
    unmapShm();
    return 0;
}

void SecKeyShm::printShm()
{
    ShmMsg *shmAddr = (ShmMsg *)mapShm();
    if (shmAddr == nullptr)
    {
        fprintf(stderr, "SecKeyShm::printShm mapShm() Err:\n");
        return;
    }
    for (int i = 0; i < maxNode; i++)
    {
        if (shmAddr->status == BUSYSPACE)
        {
            printf("status->%d\nseckeyId->%d\n", shmAddr->status, shmAddr->seckeyId);
            printf("clientId->%s\nserverId->%s\nseckey->%s\n", shmAddr->clientId, shmAddr->serverId, shmAddr->seckey);
        }
        ++shmAddr;
    }
    unmapShm();
}

int SecKeyShm::initeShm()
{
    /*初始化status为-1，其余全为0*/
    ShmMsg *pAddr = (ShmMsg *)mapShm();
    if (pAddr == nullptr)
    {
        fprintf(stderr, "SecKeyShm::initeShm mapShm Err:\n");
        return -1;
    }
    memset(pAddr, 0x00, sizeof(struct ShmMsg));
    for (int i = 0; i < maxNode; i++)
    {
        pAddr->status = SPARESPACE;
        pAddr++;
    }
    unmapShm();
    return 0;
}