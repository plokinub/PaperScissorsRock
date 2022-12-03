#pragma once

#include <string>

#include "hand.hpp"

class Rock : public Hand
{
public:
    Rock() = default;
    static const std::string GetNameStatic() { return "Rock"; };
    const std::string GetName() override { return "Rock"; };
};