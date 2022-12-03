#pragma once

#include <string>
#include <vector>
#include <memory>
#include "interface/IDispatcher.hpp"

class Hand
{
public:
    Hand() = default;

    void AddDispatcher(std::unique_ptr<IDispatcher> dispatcher);

    std::vector<std::unique_ptr<IDispatcher>> &GetDispatchers();
    int Dispatch(Hand &hand);
    int PlayAgainst(Hand &hand);
    virtual std::string GetName() = 0;

private:
    std::vector<std::unique_ptr<IDispatcher>> mDispatchers;
};