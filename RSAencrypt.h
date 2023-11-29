#include<iostream>
#include<openssl/rsa.h>
#include<openssl/pem.h>
#include<openssl/obj_mac.h>
#include<string.h>
#include<openssl/err.h>


/*思路
实现的功能：
1.创建rsa，方式有两种，
    (1)重新创建rsa
    (2)从文件中读取rsa
1.私钥签名，公钥验证
2.公钥加密，私钥解密
3.将秘钥写入.pem文件
4.从.pem文件中读取秘钥
共有的属性
rsa

*/
class RSAencrypt{
public:
    RSAencrypt();//重新创建rsa

    ~RSAencrypt();
    bool createRSA();
    bool createRSA(const char* rsaPubFilePath,const char* rsaPrivateFilePath);//从已有的文件中读取rsa
    bool saveRSAToFile(const char* rsaPubFilePath,const char* rsaPrivateFilePath);
    std::string RSAPublicEncrypt(std::string data);//公钥加密
    std::string RSAPrivateDecrypt(std::string data);//私钥解密
    bool RSAPrivateSign(std::string data,std::string& res);//私钥签名
    bool RSAPublicValidate(std::string data,std::string& res);//公钥验证
private:
    RSA* rsa;
    RSA* rsaPublic;
    RSA* rsaPrivate;
    BIGNUM* bignum;
};