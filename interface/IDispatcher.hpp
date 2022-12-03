#pragma once

#include <stdexcept>
#include <string_view>

class IDispatcher
{
public:
    IDispatcher(int action) : mAction(action){};
    int GetAction() { return mAction; };
    virtual constexpr std::string_view GetName() = 0;

protected:
    int mAction;
};