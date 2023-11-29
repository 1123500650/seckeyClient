#include"HashString.h"


HashString::HashString(HashType hashType):hashType(hashType){
    typeSize[USESHA1] = SHA_DIGEST_LENGTH;
    typeSize[USESHA224] = SHA224_DIGEST_LENGTH;
    typeSize[USESHA256] = SHA256_DIGEST_LENGTH;
    typeSize[USESHA384] = SHA384_DIGEST_LENGTH;
    typeSize[USESHA512] = SHA512_DIGEST_LENGTH;
}

HashString::~HashString(){}

unsigned char* HashString::getHashString(const char* data,unsigned int dataLen){
    unsigned char* md = new unsigned char[typeSize[hashType]];
    if(md == nullptr){
        return nullptr;
    }
    switch(hashType){
        case USESHA1:
            SHA1((unsigned char*)data,dataLen,md);
            break;
        case USESHA224:
            SHA224((unsigned char*)data,dataLen,md);
            break;
        case USESHA384:
            SHA384((unsigned char*)data,dataLen,md);
            break;
        case USESHA256:
            SHA256((unsigned char*)data,dataLen,md);
            break;
        case USESHA512:
            SHA512((unsigned char*)data,dataLen,md);
            break;
        default:
            return nullptr;
    }
    return md;
}


std::string HashString::getHashResult(const char* data,unsigned int dataLen){
    unsigned char* md = getHashString(data,dataLen);
    if(md == nullptr){
        return std::string();
    }
    char result[typeSize[hashType]*2+1] = {0};
    for(int i=0;i<typeSize[hashType];i++){
        sprintf(&result[i*2],"%02hhx",md[i]);
    }
    if(md != nullptr){
        delete[] md;
        md = nullptr;
    }
    return std::string(result,typeSize[hashType]*2+1);
}
