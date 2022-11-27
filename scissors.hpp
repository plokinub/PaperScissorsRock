#pragma once

#include <string>

#include "hand.hpp"

class Scissors : public Hand
{
public:
    Scissors(std::string name);
    void Accept(Visitor &visitor) override;
}