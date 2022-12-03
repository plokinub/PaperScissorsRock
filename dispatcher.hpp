#pragma once

#include "interface/IDispatcher.hpp"

#include <string>
#include <string_view>

template <class Hand>
class Dispatcher : public IDispatcher
{
public:
    Dispatcher(int action, std::optional<std::string> actionName = std::nullopt) : IDispatcher(action, actionName), mName(Hand::GetNameStatic()) {}

    constexpr std::string_view GetName() override
    {
        return std::string_view{mName};
    }

private:
    const std::string mName;
};