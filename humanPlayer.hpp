#pragma once

#include "interface/IPlayer.hpp"

class HumanPlayer : public IPlayer
{
public:
    HumanPlayer(IHandFactory &handFactory) : IPlayer(handFactory) {}
    std::unique_ptr<Hand> PlayHand() override;
};