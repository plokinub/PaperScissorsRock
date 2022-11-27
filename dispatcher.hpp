#pragma once

#include "IDispatcher.hpp"
#include "hand.hpp"

template <class Hand>
class Dispatcher : public IDispatcher
{
public:
    Dispatcher(int action) : IDispatcher(action){};
    std::string GetName() { return Hand::GetNameStatic(); };
};