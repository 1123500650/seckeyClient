#include"JsonString.h"


JsonString::JsonString(){

}

JsonString::~JsonString(){

}

bool JsonString::writeToJson(ClientInfo& info){
    root["clientId"] = info.clientId;
    root["serverId"] = info.serverId;
    root["serverIp"] = info.serverIp;
    root["port"] = info.port;
    std::ofstream ofs("config.json");
    ofs<<root;
    ofs.close();
    return true;
}


bool JsonString::readFromJson(ClientInfo& info){
    std::ifstream ifs("config.json");
    Json::Reader reader;
    reader.parse(ifs,root);
    info.clientId = root["clientId"].asString();
    info.serverId = root["serverId"].asString();
    info.serverIp = root["serverIp"].asString();
    info.port = root["port"].asInt();
    ifs.close();
    return true;
}