#pragma once

#include <stdexcept>

class IDispatcher
{
public:
    IDispatcher(int action) : mAction(action){};
    int GetAction() { return mAction; };
    virtual std::string GetName() { throw std::runtime_error("Not implemented"); };

protected:
    int mAction;
};