#pragma once

#include <stdexcept>
#include <string_view>
#include <optional>
#include "../action.hpp"

class IDispatcher
{
public:
    IDispatcher(int action, std::optional<std::string> actionName = std::nullopt) : mAction(action, actionName){};
    const Result &GetAction() { return mAction; };
    virtual constexpr std::string_view GetName() = 0;

protected:
    const Result mAction;
};