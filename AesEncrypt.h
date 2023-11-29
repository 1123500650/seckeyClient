#pragma once
#include<iostream>
#include<openssl/aes.h>
#include<string.h>

class AesEncrypt{
public:
    AesEncrypt();
    ~AesEncrypt();
    bool initeEncryptKey(std::string seckey);
    bool initeDecryptKey(std::string seckey);
    std::string getEncryptRes(std::string inData,std::string ivec);
    std::string getDecryptRes(std::string inData,std::string ivec);
private:
    AES_KEY key;
};
