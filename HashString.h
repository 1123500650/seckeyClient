#pragma once
#include<openssl/sha.h>
#include<iostream>
#include<unordered_map>

class HashString{
public:
    enum HashType {USESHA1,USESHA224,USESHA256,USESHA384,USESHA512};
    HashString(HashType hashType);
    ~HashString();
    std::string getHashResult(const char* data,unsigned int dataLen);
private:
    HashType hashType;
    unsigned char* getHashString(const char* data,unsigned int dataLen);
    std::unordered_map<HashType,unsigned int>typeSize;
};