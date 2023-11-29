#pragma once
#include <iostream>
#include <string>

class Codec
{
public:
    Codec();
    ~Codec();
    virtual void msgSeraize(std::string &sendMsg) = 0;
    virtual void* msgParse(std::string &recvMsg) = 0;
};