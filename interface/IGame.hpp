#pragma once

#include "IRound.hpp"
#include "IHandFactory.hpp"

class IGame
{
public:
    IGame(){};
    virtual void Setup() = 0;
    virtual void Play() = 0;
};