#pragma once

#include "interface/IPlayer.hpp"

#include <random>

class BotPlayer : public IPlayer
{
public:
    BotPlayer(IHandFactory &handFactory) : IPlayer("Computer", handFactory) {}
    std::unique_ptr<Hand> PlayHand() override;
};