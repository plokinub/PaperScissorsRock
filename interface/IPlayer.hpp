#pragma once

#include "IHandFactory.hpp"

#include <memory>
#include <string>
#include <string_view>
#include "../hand.hpp"

class IPlayer
{
public:
    IPlayer(std::string name, IHandFactory &handFactory) : mName(name), mHandFactory(handFactory) {}
    virtual std::unique_ptr<Hand> PlayHand() = 0;
    const std::string_view GetName() { return mName; }

protected:
    const std::string mName;
    IHandFactory &mHandFactory;
};