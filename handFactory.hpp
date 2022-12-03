#pragma once

#include "hand.hpp"
#include <memory>
#include <random>

#include "interface/IHandFactory.hpp"

const int HANDS_COUNT = 3;

class HandFactory : public IHandFactory
{

public:
    HandFactory() = default;

    std::unique_ptr<Hand> CreateRandomHand() override;

    template <class HandType>
    std::unique_ptr<Hand> CreateHand()
    {
        throw std::runtime_error("Unimplemented CreateHand() for this type");
    }

private:
    std::mt19937 mRandomGenerator{std::random_device{}()};
    std::uniform_int_distribution<> mRandomDistribution{1, HANDS_COUNT};
};