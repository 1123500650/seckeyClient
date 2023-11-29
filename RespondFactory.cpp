#include "RespondFactory.h"

RespondFactory::RespondFactory()
{
    flag = 1;
}

RespondFactory::RespondFactory(RespondMsg &msg) : m_msg(msg)
{
    flag = 2;
}

Codec *RespondFactory::createFactory()
{
    Codec* res = nullptr;
    switch (flag)
    {
    case 1:
        res = new RespondCodec();
        break;
    case 2:
        res =  new RespondCodec(m_msg);
        break;
    default:
        std::cout << "RespondFactory::createFactory() Error" << std::endl;
        break;
    }
    return res;
}

RespondFactory::~RespondFactory()
{
}