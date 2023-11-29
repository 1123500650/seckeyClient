#include"RequestFactory.h"


RequestFactory::RequestFactory(){
    flag = 1;
}

RequestFactory::RequestFactory(RequestMsg& msg):m_msg(msg){
    flag = 2;
}

Codec* RequestFactory::createFactory(){
    if(flag == 1){
        return new RequestCodec();
    }
    return new RequestCodec(m_msg);
}

RequestFactory::~RequestFactory(){
    
}