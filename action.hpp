#pragma once

#include <string>
#include <optional>

class Result
{
public:
    Result(int action, std::optional<std::string> actionName) : mAction(action), mActionName(actionName){};

    int GetAction() { return mAction; };
    constexpr const std::optional<std::string> &GetActionName()
    {
        return mActionName;
    }

private:
    const int mAction;
    const std::optional<std::string> mActionName;
};