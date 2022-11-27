#pragma once

#include <string>

#include "hand.hpp"

class Scissors : public Hand
{
public:
    Scissors() = default;
    static std::string GetNameStatic() { return "Scissors"; };
    std::string GetName() override { return Scissors::GetNameStatic(); };
};