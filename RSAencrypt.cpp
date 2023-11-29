#include "RSAencrypt.h"
#include <openssl/sha.h>
RSAencrypt::RSAencrypt() : rsa(nullptr), rsaPrivate(nullptr), rsaPublic(nullptr) {}

RSAencrypt::~RSAencrypt()
{
    if(rsaPublic != nullptr){
        RSA_free(rsaPublic);
        rsaPublic = nullptr;
    }
    if(rsaPrivate != nullptr){
        RSA_free(rsaPrivate);
        rsaPrivate = nullptr;
    }
    if (rsa != nullptr)
    {
        RSA_free(rsa);
        rsa = nullptr;
    }
}

bool RSAencrypt::createRSA()
{
    rsa = RSA_new();
    // 初始化bignum
    bignum = BN_new();
    BN_set_word(bignum, 12345);
    // 生成秘钥对，存储在内存中
    int ret = RSA_generate_key_ex(rsa, 2048, bignum, nullptr);
    if (ret != 1)
    {
        std::cerr << "createRSA err" << std::endl;
        return false;
    }
    // 将公钥从rsa中提取出来
    rsaPublic = RSAPublicKey_dup(rsa);
    // 将私钥从rsa中提取出来
    rsaPrivate = RSAPrivateKey_dup(rsa);
    if (bignum != nullptr)
    {
        BN_free(bignum);
        bignum = nullptr;
    }
    return true;
}

bool RSAencrypt::createRSA(const char *rsaPubFilePath, const char *rsaPrivateFilePath)
{
    if(rsaPubFilePath != nullptr){
        BIO *bio = BIO_new_file(rsaPubFilePath, "r");
        if (bio == nullptr)
        {
            std::cout << "BIO_new_file Error" << std::endl;
            return false;
        }
        // 将公钥读入rsa
        rsaPublic = PEM_read_bio_RSAPublicKey(bio, nullptr, nullptr, nullptr);
        BIO_free(bio);
    }
    if(rsaPrivateFilePath != nullptr){
        BIO *bio = BIO_new_file(rsaPrivateFilePath, "r");
        if (bio == nullptr)
        {
            std::cout << "BIO_new_file Error" << std::endl;
            return false;
        }
        rsaPrivate = PEM_read_bio_RSAPrivateKey(bio, nullptr, nullptr, nullptr);
        BIO_free(bio);
    }
    return true;
}

bool RSAencrypt::saveRSAToFile(const char *rsaPubFilePath, const char *rsaPrivateFilePath)
{
    if(rsaPubFilePath != nullptr){
        BIO *bio = BIO_new_file(rsaPubFilePath, "w");
        if (bio == nullptr)
        {
            std::cout << "BIO_new_file Error" << std::endl;
            return false;
        }
        // 将公钥写入rsa_pub.em
        int ret = PEM_write_bio_RSAPublicKey(bio, rsaPublic);
        if (ret != 1)
        {
            std::cerr << "publicKey write error" << std::endl;
            return false;
        }
        BIO_free(bio);
    }
    if(rsaPrivateFilePath != nullptr){
        BIO *bio = BIO_new_file(rsaPrivateFilePath, "w");
        if (bio == nullptr)
        {
            std::cout << "BIO_new_file Error" << std::endl;
            return false;
        }
        int ret = PEM_write_bio_RSAPrivateKey(bio, rsaPrivate, nullptr, nullptr, 0, nullptr, nullptr);
        if (ret != 1)
        {
            std::cerr << "privateKey write error" << std::endl;
            return false;
        }
        BIO_free(bio);
    }
    return true;
}


std::string RSAencrypt::RSAPublicEncrypt(std::string data)
{
    const char *dataCstr = data.data();
    char *outData = new char[256];
    int outDataLen = RSA_public_encrypt(data.size(), (unsigned char *)dataCstr, (unsigned char *)outData, rsaPublic, RSA_PKCS1_PADDING);
    std::string outDataString(outData, outDataLen);
    if (outData != nullptr)
    {
        delete[] outData;
        outData = nullptr;
    }
    return outDataString;
}

std::string RSAencrypt::RSAPrivateDecrypt(std::string data)
{
    const char *dataCstr = data.data();
    char *outData = new char[256];
    int outDataLen = RSA_private_decrypt(data.size(), (unsigned char *)dataCstr, (unsigned char *)outData, rsaPrivate, RSA_PKCS1_PADDING);
    std::string outDataString(outData, outDataLen);
    if (outData != nullptr)
    {
        delete[] outData;
        outData = nullptr;
    }
    return outDataString;
}

bool RSAencrypt::RSAPrivateSign(std::string data, std::string &res)
{
    const char *dataCstr = new char[SHA_DIGEST_LENGTH];
    SHA1((unsigned char*)data.data(),data.size(),(unsigned char*)dataCstr);

    char *outDataCstr = new char[RSA_size(rsaPrivate)];
    unsigned int resDataLen;
    int ret = RSA_sign(NID_sha1, (unsigned char *)dataCstr, SHA_DIGEST_LENGTH, (unsigned char *)outDataCstr, &resDataLen, rsaPrivate);
    if (ret != 1)
    {
        ERR_print_errors_fp(stderr);
        std::cerr << "RSA_sign Error" << std::endl;
        return false;
    }
    res = std::string(outDataCstr, resDataLen);
    if (outDataCstr != nullptr)
    {
        delete[] outDataCstr;
        outDataCstr = nullptr;
    }
    return true;
}

bool RSAencrypt::RSAPublicValidate(std::string data, std::string &res)
{
    const char *dataCstr = new char[SHA_DIGEST_LENGTH];
    SHA1((unsigned char*)data.data(),data.size(),(unsigned char*)dataCstr);

    const char *resCstr = res.data();
    int ret = RSA_verify(NID_sha1, (unsigned char *)dataCstr, SHA_DIGEST_LENGTH, (unsigned char *)resCstr, res.size(), rsaPublic);
    if (ret == 1)
    {
        return true;
    }
    return false;
}
