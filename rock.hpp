#pragma once

#include <string>

#include "hand.hpp"

class Rock : public Hand
{
public:
    Rock() = default;
    static std::string GetNameStatic() { return "Rock"; };
    std::string GetName() override { return Rock::GetNameStatic(); };
};