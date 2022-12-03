#pragma once

#include <string>
#include <vector>
#include <memory>
#include "interface/IDispatcher.hpp"
#include "action.hpp"

class Hand
{
public:
    Hand() = default;

    void AddDispatcher(std::unique_ptr<IDispatcher> dispatcher);

    std::vector<std::unique_ptr<IDispatcher>> &GetDispatchers();
    Result Dispatch(Hand &hand);
    Result PlayAgainst(Hand &hand);
    virtual const std::string GetName() = 0;

private:
    std::vector<std::unique_ptr<IDispatcher>> mDispatchers;
};