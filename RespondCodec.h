#pragma once
#include"Codec.h"
#include"RespondProtobuf.pb.h"

enum RespondStatus {STATUS_FAULT=-1,STATUS_NOTEQUAL=0,STATUS_OK=1,STATUS_DEFAULT=2};
struct  RespondMsg
{
	int	status;		// 返回值
	std::string clientId;	// 客户端编号
	std::string serverId;	// 服务器编号
	std::string data;		// 服务器端随机数
	int	seckeyid;	// 对称密钥编号    keysn
    RespondMsg(){
        status = STATUS_DEFAULT;
        seckeyid = 0;
    };
    RespondMsg(int rv,std::string clientId,std::string serverId,std::string r2,int seckeyid):status(status),clientId(clientId),
    serverId(serverId),data(data),seckeyid(seckeyid){};
};

class RespondCodec:public Codec {
public:
    RespondCodec();
    RespondCodec(RespondMsg& msg);
    ~RespondCodec();
    void msgSeraize(std::string& sendMsg);
    void* msgParse(std::string& recvMsg);
private:
    RespondMsg m_msg;
};