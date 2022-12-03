#pragma once

#include "IHandFactory.hpp"

#include <memory>
#include "../hand.hpp"

class IPlayer
{
public:
    IPlayer(IHandFactory &handFactory) : mHandFactory(handFactory) {}
    virtual std::unique_ptr<Hand> PlayHand() = 0;

protected:
    IHandFactory &mHandFactory;
};