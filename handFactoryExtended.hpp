#pragma once

#include "interface/IHandFactory.hpp"

#include <memory>
#include <random>

#include "hand.hpp"

class ExtendedHandFactory : public IHandFactory
{

private:
    const int HANDS_COUNT = 5;

public:
    ExtendedHandFactory() = default;

    std::unique_ptr<Hand> CreateRandomHand() override;
    std::unique_ptr<Hand> CreateHandFromString(std::string handName) override;

    template <class HandType>
    std::unique_ptr<Hand> CreateHand()
    {
        throw std::runtime_error("Unimplemented CreateHand() for this type");
    }

protected:
    std::mt19937 mRandomGenerator{std::random_device{}()};
    std::uniform_int_distribution<int> mRandomDistribution{1, HANDS_COUNT};
};