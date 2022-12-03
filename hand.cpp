#include "hand.hpp"
#include <stdexcept>

void Hand::AddDispatcher(std::unique_ptr<IDispatcher> dispatcher)
{
    mDispatchers.push_back(std::move(dispatcher));
}

std::vector<std::unique_ptr<IDispatcher>> &Hand::GetDispatchers()
{
    return mDispatchers;
}

Result Hand::Dispatch(Hand &hand)
{
    for (auto &dispatcher : mDispatchers)
    {
        if (dispatcher->GetName() == hand.GetName())
        {
            return dispatcher->GetAction();
        }
    }
    throw std::runtime_error("Dont know how to play this hand...");
}

Result Hand::PlayAgainst(Hand &hand)
{
    return Dispatch(hand);
}