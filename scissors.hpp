#pragma once

#include <string>

#include "hand.hpp"

class Scissors : public Hand
{
public:
    Scissors() = default;
    static const std::string GetNameStatic() { return "Scissors"; };
    const std::string GetName() override { return "Scissors"; };
};