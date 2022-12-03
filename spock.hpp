#pragma once

#include <string>

#include "hand.hpp"

class Spock : public Hand
{
public:
    Spock() = default;
    static const std::string GetNameStatic() { return "Spock"; };
    const std::string GetName() override { return "Spock"; };
};