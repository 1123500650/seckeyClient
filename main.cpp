#include<iostream>
#include"ClientWorking.h"


int main(){
    ClientWorking client;
    if(!client.readJsonFile){
        return -1;
    }
    while(1){
        std::cout<<"=============密钥协商系统============="<<std::endl;
        std::cout<<"=============01秘钥协商============="<<std::endl;
        std::cout<<"=============02秘钥校验============="<<std::endl;
        std::cout<<"=============03秘钥注销============="<<std::endl;
        int cmdType;
        std::cin>>cmdType;
        switch(cmdType){
            case 1:
                client.seckeyNegotiate();
                break;
            case 2:
                client.seckeyValidate();
                break;
            case 3:
                client.seckeyLogout();
                break;
            default:
                return 0;
        }
    }
    return 0;
}