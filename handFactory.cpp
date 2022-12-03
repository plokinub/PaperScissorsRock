#include "handFactory.hpp"

#include "paper.hpp"
#include "scissors.hpp"
#include "rock.hpp"
#include "dispatcher.hpp"

using std::make_unique;
using std::move;
using std::unique_ptr;

template <>
std::unique_ptr<Hand> HandFactory::CreateHand<Rock>()
{
    auto hand = std::make_unique<Rock>();
    hand->AddDispatcher(move(make_unique<Dispatcher<Rock>>(0, "draws with")));
    hand->AddDispatcher(move(make_unique<Dispatcher<Paper>>(-1, "is covered by")));
    hand->AddDispatcher(move(make_unique<Dispatcher<Scissors>>(1, "crushes")));
    return hand;
}

template <>
std::unique_ptr<Hand> HandFactory::CreateHand<Scissors>()
{
    auto hand = std::make_unique<Scissors>();
    hand->AddDispatcher(move(make_unique<Dispatcher<Scissors>>(0, "draws with")));
    hand->AddDispatcher(move(make_unique<Dispatcher<Paper>>(1, "cuts")));
    hand->AddDispatcher(move(make_unique<Dispatcher<Rock>>(-1, "is crushed by")));
    return hand;
}

template <>
std::unique_ptr<Hand> HandFactory::CreateHand<Paper>()
{
    auto hand = make_unique<Paper>();
    hand->AddDispatcher(move(make_unique<Dispatcher<Paper>>(0, "draws with")));
    hand->AddDispatcher(move(make_unique<Dispatcher<Rock>>(1, "covers")));
    hand->AddDispatcher(move(make_unique<Dispatcher<Scissors>>(-1, "is cut by")));
    return hand;
}

std::unique_ptr<Hand> HandFactory::CreateRandomHand()
{
    auto randNum = mRandomDistribution(mRandomGenerator);
    switch (randNum)
    {
    case 1:
        return CreateHand<Rock>();
    case 2:
        return CreateHand<Paper>();
    case 3:
        return CreateHand<Scissors>();
    default:
        throw std::runtime_error("Could not create random hand");
    }
}

std::unique_ptr<Hand> HandFactory::CreateHandFromString(std::string handName)
{
    if (handName == "rock")
    {
        return CreateHand<Rock>();
    }
    else if (handName == "paper")
    {
        return CreateHand<Paper>();
    }
    else if (handName == "scissors")
    {
        return CreateHand<Scissors>();
    }
    else
    {
        throw std::runtime_error("Could not create hand from string");
    }
}