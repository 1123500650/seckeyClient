#include"RequestCodec.h"
#include<string.h>

RequestCodec::RequestCodec(){

}

RequestCodec::RequestCodec(RequestMsg& msg):m_msg(msg){//这里建议用初始化列表实现属性的初始化，否则，如果在构造函数中赋值，会先调用默认构造再调用拷贝构造
    // std::cout<<"before"<<std::endl;
    // m_msg = msg;
}

void RequestCodec::msgSeraize(std::string &sendMsg){
    protobuf::RequestProtobuf requestProtobuf;
    requestProtobuf.set_sign(m_msg.sign);
    requestProtobuf.set_clientid(m_msg.clientId);
    requestProtobuf.set_cmdtype(m_msg.cmdType);
    requestProtobuf.set_data(m_msg.data);
    requestProtobuf.set_serverid(m_msg.serverId); 
    
    requestProtobuf.SerializeToString(&sendMsg);
}

void* RequestCodec::msgParse(std::string &recvMsg){
    protobuf::RequestProtobuf requestProtobuf;
    requestProtobuf.ParseFromString(recvMsg);
    memset(&m_msg,0x00,sizeof(RequestMsg));
    m_msg.sign = requestProtobuf.sign();
    m_msg.clientId = requestProtobuf.clientid();
    m_msg.cmdType = requestProtobuf.cmdtype();
    m_msg.data = requestProtobuf.data();
    m_msg.serverId = requestProtobuf.serverid();
    return &m_msg;
}
