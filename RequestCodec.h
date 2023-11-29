#pragma once
#include"Codec.h"
#include"RequestProtobuf.pb.h"

struct RequestMsg
{
public:
    int	cmdType;		// 报文类型
	std::string	clientId;	// 客户端编号
	std::string	sign;	// 认证码
	std::string	serverId;	// 服务器端编号 
	std::string	data;			// 客户端随机数
    RequestMsg(){
        cmdType = 0;
        // std::cout<<"RequestMsg的默认构造"<<std::endl;
    };
    RequestMsg(int cmdType,std::string clientId,std::string sign,std::string serverId,std::string data):cmdType(cmdType),
    sign(sign),clientId(clientId),serverId(serverId),data(data){
        // std::cout<<"RequestMsg的有参构造"<<std::endl;
    };
};

enum CMDTYPE{SECKEYNEGOTIATE=1,SECKEYVALIDATE,SECKEYLOGOUT};

class RequestCodec:public Codec {  //这里犯了一个错误，在继承时，一定要指定类的继承方式，否则默认是私有继承，那么基类的构造函数在类外无法访问
public:
    RequestCodec();
    RequestCodec(RequestMsg& requestMsg);
    ~RequestCodec();
    void msgSeraize(std::string &sendMsg);
    void* msgParse(std::string &recvMsg);
private:
    RequestMsg m_msg;
};