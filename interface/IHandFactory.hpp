#pragma once

#include "../hand.hpp"

class IHandFactory
{
public:
    IHandFactory() = default;
    virtual std::unique_ptr<Hand> CreateRandomHand() = 0;
};