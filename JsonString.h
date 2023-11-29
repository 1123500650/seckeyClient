#pragma once
#include<iostream>
#include<jsoncpp/json/json.h>
#include<fstream>

/*
客户端需要提供的配置文件
{
    clientId:"0001";
    serverId:"1000";
    serverIp:"127.0.0.1";
    serverPort:8888;
}
*/

/*
目标：
1.写配置文件
2.读取配置文件
*/

struct ClientInfo{
    std::string clientId;
    std::string serverId;
    std::string serverIp;
    unsigned int port;
};


class JsonString{
public:
    JsonString();
    ~JsonString();
    bool writeToJson(ClientInfo& info);
    bool readFromJson(ClientInfo& info);
private:
    Json::Value root;
};