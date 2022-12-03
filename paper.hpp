#pragma once

#include <string>

#include "hand.hpp"

class Paper : public Hand
{
public:
    Paper() = default;
    static const std::string GetNameStatic() { return "Paper"; };
    const std::string GetName() override { return "Paper"; };
};