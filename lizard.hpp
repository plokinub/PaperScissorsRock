#pragma once

#include <string>

#include "hand.hpp"

class Lizard : public Hand
{
public:
    Lizard() = default;
    static const std::string GetNameStatic() { return "Lizard"; };
    const std::string GetName() override { return "Lizard"; };
};