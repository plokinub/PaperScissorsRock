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
    hand->AddDispatcher(move(make_unique<Dispatcher<Rock>>(0)));
    hand->AddDispatcher(move(make_unique<Dispatcher<Paper>>(-1)));
    hand->AddDispatcher(move(make_unique<Dispatcher<Scissors>>(1)));
    return hand;
}

template <>
std::unique_ptr<Hand> HandFactory::CreateHand<Scissors>()
{
    auto hand = std::make_unique<Scissors>();
    hand->AddDispatcher(move(make_unique<Dispatcher<Scissors>>(0)));
    hand->AddDispatcher(move(make_unique<Dispatcher<Paper>>(1)));
    hand->AddDispatcher(move(make_unique<Dispatcher<Rock>>(-1)));
    return hand;
}

template <>
std::unique_ptr<Hand> HandFactory::CreateHand<Paper>()
{
    auto hand = make_unique<Paper>();
    hand->AddDispatcher(move(make_unique<Dispatcher<Paper>>(0)));
    hand->AddDispatcher(move(make_unique<Dispatcher<Rock>>(1)));
    hand->AddDispatcher(move(make_unique<Dispatcher<Scissors>>(-1)));
    return hand;
}