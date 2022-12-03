#pragma once

#include "IPlayer.hpp"

#include <vector>

class IRound
{
public:
    IRound(std::vector<std::unique_ptr<IPlayer>> &players) : mPlayers(players){};
    virtual void Play() = 0;

protected:
    std::vector<std::unique_ptr<IPlayer>> &mPlayers;
};