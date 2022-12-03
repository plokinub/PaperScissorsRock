#include "botPlayer.hpp"

#include <type_traits>

std::unique_ptr<Hand> BotPlayer::PlayHand()
{
    return mHandFactory.CreateRandomHand();
}