#pragma once

#include <string>

#include "hand.hpp"

class Paper : public Hand
{
public:
    Paper() = default;
    static std::string GetNameStatic() { return "Paper"; };
    std::string GetName() override { return Paper::GetNameStatic(); };
};