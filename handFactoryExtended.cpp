#include "handFactoryExtended.hpp"

#include <boost/algorithm/string.hpp>

#include "lizard.hpp"
#include "spock.hpp"

#include "paper.hpp"
#include "scissors.hpp"
#include "rock.hpp"
#include "dispatcher.hpp"
#include "helpers.hpp"

using std::make_unique;
using std::move;
using std::unique_ptr;

template <>
std::unique_ptr<Hand> ExtendedHandFactory::CreateHand<Rock>()
{
    auto hand = std::make_unique<Rock>();
    hand->AddDispatcher(move(make_unique<Dispatcher<Rock>>(0)));
    hand->AddDispatcher(move(make_unique<Dispatcher<Paper>>(-1)));
    hand->AddDispatcher(move(make_unique<Dispatcher<Scissors>>(1)));
    hand->AddDispatcher(move(make_unique<Dispatcher<Lizard>>(1)));
    hand->AddDispatcher(move(make_unique<Dispatcher<Spock>>(-1)));
    return hand;
}

template <>
std::unique_ptr<Hand> ExtendedHandFactory::CreateHand<Scissors>()
{
    auto hand = std::make_unique<Scissors>();
    hand->AddDispatcher(move(make_unique<Dispatcher<Scissors>>(0)));
    hand->AddDispatcher(move(make_unique<Dispatcher<Paper>>(1)));
    hand->AddDispatcher(move(make_unique<Dispatcher<Rock>>(-1)));
    hand->AddDispatcher(move(make_unique<Dispatcher<Lizard>>(1)));
    hand->AddDispatcher(move(make_unique<Dispatcher<Spock>>(-1)));
    return hand;
}

template <>
std::unique_ptr<Hand> ExtendedHandFactory::CreateHand<Paper>()
{
    auto hand = make_unique<Paper>();
    hand->AddDispatcher(move(make_unique<Dispatcher<Paper>>(0)));
    hand->AddDispatcher(move(make_unique<Dispatcher<Rock>>(1)));
    hand->AddDispatcher(move(make_unique<Dispatcher<Scissors>>(-1)));
    hand->AddDispatcher(move(make_unique<Dispatcher<Lizard>>(-1)));
    hand->AddDispatcher(move(make_unique<Dispatcher<Spock>>(1)));
    return hand;
}

template <>
std::unique_ptr<Hand> ExtendedHandFactory::CreateHand<Lizard>()
{
    auto hand = make_unique<Lizard>();
    hand->AddDispatcher(move(make_unique<Dispatcher<Lizard>>(0)));
    hand->AddDispatcher(move(make_unique<Dispatcher<Rock>>(-1)));
    hand->AddDispatcher(move(make_unique<Dispatcher<Scissors>>(-1)));
    hand->AddDispatcher(move(make_unique<Dispatcher<Paper>>(1)));
    hand->AddDispatcher(move(make_unique<Dispatcher<Spock>>(1)));
    return hand;
}

template <>
std::unique_ptr<Hand> ExtendedHandFactory::CreateHand<Spock>()
{
    auto hand = make_unique<Spock>();
    hand->AddDispatcher(move(make_unique<Dispatcher<Spock>>(0)));
    hand->AddDispatcher(move(make_unique<Dispatcher<Rock>>(1)));
    hand->AddDispatcher(move(make_unique<Dispatcher<Scissors>>(1)));
    hand->AddDispatcher(move(make_unique<Dispatcher<Lizard>>(-1)));
    hand->AddDispatcher(move(make_unique<Dispatcher<Paper>>(-1)));
    return hand;
}

std::unique_ptr<Hand> ExtendedHandFactory::CreateRandomHand()
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
    case 4:
        return CreateHand<Lizard>();
    case 5:
        return CreateHand<Spock>();
    default:
        throw std::runtime_error("Could not create random hand");
    }
}

std::unique_ptr<Hand> ExtendedHandFactory::CreateHandFromString(std::string handName)
{
    boost::algorithm::to_lower(handName);

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
    else if (handName == "lizard")
    {
        return CreateHand<Scissors>();
    }
    else if (handName == "spock")
    {
        return CreateHand<Scissors>();
    }
    else
    {
        throw std::runtime_error("Could not create hand from string");
    }
}