#pragma once
#include<iostream>
#include"RespondFactory.h"
#include"RequestFactory.h"
#include"RSAencrypt.h"
#include"JsonString.h"
#include"TcpSocket.h"
#include<fstream>
#include"SecKeyShm.h"
#include"AesEncrypt.h"
#include"HashString.h"


class ClientWorking{
public:
    ClientWorking();
    ~ClientWorking();
    void seckeyNegotiate();
    void seckeyValidate();
    void seckeyLogout();
    bool readJsonFile;
private:
    ClientInfo clientInfo;
};