#pragma once

#include <string>

#include "hand.hpp"

class Paper : public Hand
{
public:
    Paper(std::string name);
    void Accept(Visitor &visitor) override;
};