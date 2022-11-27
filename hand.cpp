#include "hand.hpp"

std::string Hand::GetName()
{
    return mName;
}

Hand::Hand(std::string name)
{
    mName = name;
}