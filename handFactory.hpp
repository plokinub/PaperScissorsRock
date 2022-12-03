#pragma once

#include "hand.hpp"
#include <memory>

#include "interface/IHandFactory.hpp"

class HandFactory : public IHandFactory
{

public:
    HandFactory() = default;

    template <class HandType>
    std::unique_ptr<Hand> CreateHand()
    {
        throw std::runtime_error("Unimplemented CreateHand() for this type");
    }
};