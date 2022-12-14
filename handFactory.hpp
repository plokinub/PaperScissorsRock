#pragma once

#include "interface/IHandFactory.hpp"

#include <memory>
#include <random>

#include "hand.hpp"

class HandFactory : public IHandFactory
{

private:
    const int HANDS_COUNT = 3;

public:
    HandFactory() = default;

    std::unique_ptr<Hand> CreateRandomHand() override;
    std::unique_ptr<Hand> CreateHandFromString(std::string handName) override;

    template <class HandType>
    std::unique_ptr<Hand> CreateHand()
    {
        throw std::runtime_error("Unimplemented CreateHand() for this type");
    }

protected:
    std::mt19937 mRandomGenerator{std::random_device{}()};
    std::uniform_int_distribution<> mRandomDistribution{1, HANDS_COUNT};
};