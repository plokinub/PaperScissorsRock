#pragma once

#include <string>

#include "hand.hpp"

class Rock : public Hand
{
public:
    Rock(std::string name);
    void Accept(Visitor &visitor) override;
};