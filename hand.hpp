#pragma once

#include <string>
#include "visitor.hpp"

class Hand
{
public:
    Hand(std::string name);
    virtual void Accept(Visitor &visitor) = 0;
    std::string GetName();

private:
    std::string mName;
};