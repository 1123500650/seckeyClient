#pragma once
#include"BaseFactory.h"
#include"RequestCodec.h"


class RequestFactory:public BaseFactory{
public:
    RequestFactory();
    RequestFactory(RequestMsg& msg);
    ~RequestFactory();
    Codec* createFactory();
private:
    RequestMsg m_msg;
    int flag;
};
