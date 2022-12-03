#pragma once

#include "interface/IPlayer.hpp"

#include <random>
#include <string>

class BotPlayer : public IPlayer
{
public:
    BotPlayer(IHandFactory &handFactory) : IPlayer("Computer", handFactory) {}
    BotPlayer(std::string name, IHandFactory &handFactory) : IPlayer(name, handFactory) {}
    std::unique_ptr<Hand> PlayHand() override;
};