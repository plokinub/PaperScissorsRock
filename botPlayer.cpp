#include "botPlayer.hpp"

std::unique_ptr<Hand> BotPlayer::PlayHand()
{
    return mHandFactory.CreateRandomHand();
}