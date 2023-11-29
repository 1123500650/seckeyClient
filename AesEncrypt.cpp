#include"AesEncrypt.h"

AesEncrypt::AesEncrypt(){}

AesEncrypt::~AesEncrypt(){}

bool AesEncrypt::initeEncryptKey(std::string seckey){
    int ret = AES_set_encrypt_key((unsigned char*)seckey.data(),AES_BLOCK_SIZE*8,&key);
    if(ret != 0){
        std::cerr<<"AesEncrypt::initeEncryptKey AES_set_encrypt_key Err"<<std::endl;
        return false;
    }
    return true;
}

bool AesEncrypt::initeDecryptKey(std::string seckey){
    int ret = AES_set_decrypt_key((unsigned char*)seckey.data(),AES_BLOCK_SIZE*8,&key);
    if(ret != 0){
        std::cerr<<"AesEncrypt::initeEncryptKey AES_set_decrypt_key Err"<<std::endl;
        return false;
    }
    return true;
}

std::string AesEncrypt::getEncryptRes(std::string inData,std::string ivec){
    int dataLen = (inData.size() + AES_BLOCK_SIZE -1)/AES_BLOCK_SIZE*AES_BLOCK_SIZE;
    char* outData = new char[dataLen];
    char* theData = new char[dataLen];
    int padding = dataLen - inData.size();
    memcpy(theData,inData.c_str(),inData.size());
    for(int i = inData.size();i<dataLen;i++){
        theData[i] = padding;
    }
    AES_cbc_encrypt((unsigned char*)theData,(unsigned char*)outData,dataLen,&key,(unsigned char*)ivec.data(),AES_ENCRYPT);
    std::string res(outData,dataLen);
    if(outData != nullptr){
        delete[] outData;
        outData = nullptr;
    }
    if(theData != nullptr){
        delete[] theData;
        theData = nullptr;
    }
    return res;
}

std::string AesEncrypt::getDecryptRes(std::string inData,std::string ivec){
    int dataLen = (inData.size() + AES_BLOCK_SIZE -1)/AES_BLOCK_SIZE*AES_BLOCK_SIZE;
    char* outData = new char[dataLen];
    memset(outData,0x00,sizeof(dataLen));
    AES_cbc_encrypt((unsigned char*)inData.data(),(unsigned char*)outData,dataLen,&key,(unsigned char*)ivec.data(),AES_DECRYPT);
    int padding = outData[dataLen - 1];
    int count = padding;
    char* p = outData + dataLen - 1;
    while(*p == padding&&count-->0){
        p--;
    }
    if(count==0){
        dataLen = dataLen - padding;
    }
    std::string res(outData,dataLen);
    if(outData != nullptr){
        delete[] outData;
        outData = nullptr;
    }
    return res;
}