#pragma once

#include "interface/IPlayer.hpp"

#include <string>

class HumanPlayer : public IPlayer
{
public:
    HumanPlayer(std::string name, IHandFactory &handFactory) : IPlayer(name, handFactory) {}
    std::unique_ptr<Hand> PlayHand() override;
};