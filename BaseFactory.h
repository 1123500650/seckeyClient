#pragma once
#include<iostream>
#include"Codec.h"

class BaseFactory{
public:
    BaseFactory();
    virtual ~BaseFactory() = 0;
    virtual Codec* createFactory() = 0;
};