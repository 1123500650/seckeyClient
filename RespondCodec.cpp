#include"RespondCodec.h"
#include<string.h>

RespondCodec::RespondCodec(){
}

RespondCodec::RespondCodec(RespondMsg&msg){
    m_msg = msg;
}

void RespondCodec::msgSeraize(std::string& sendMsg){
    protobuf::RespondProto respondProtobuf;
    respondProtobuf.set_clientid(m_msg.clientId);
    respondProtobuf.set_data(m_msg.data);
    respondProtobuf.set_stauts(m_msg.status);
    respondProtobuf.set_seckeyid(m_msg.seckeyid);
    respondProtobuf.set_serverid(m_msg.serverId);
    respondProtobuf.SerializeToString(&sendMsg);
}

void* RespondCodec::msgParse(std::string& recvMsg){
    protobuf::RespondProto respondProtobuf;
    respondProtobuf.ParseFromString(recvMsg);
    m_msg.clientId = respondProtobuf.clientid();
    m_msg.data = respondProtobuf.data();
    m_msg.status = respondProtobuf.stauts();
    m_msg.seckeyid = respondProtobuf.seckeyid();
    m_msg.serverId = respondProtobuf.serverid();
    return &m_msg;
}

