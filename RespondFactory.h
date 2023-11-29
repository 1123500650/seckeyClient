#pragma once
#include"BaseFactory.h"
#include"RespondCodec.h"

class RespondFactory:public BaseFactory{
public:
    RespondFactory();
    RespondFactory(RespondMsg&msg);
    ~RespondFactory();
    Codec* createFactory();
private:
    RespondMsg m_msg;
    int flag;
};