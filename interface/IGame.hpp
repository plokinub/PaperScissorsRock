#pragma once

#include "IRound.hpp"
#include "IHandFactory.hpp"
#include "IPlayer.hpp"

class IGame
{
public:
    IGame(){};
    virtual void Setup() = 0;
    virtual void Play() = 0;
    virtual void PrintScores()
    {
        for (const auto &player : mPlayers)
        {
            std::cout << player->GetName() << " won " << player->GetScore() << " rounds." << std::endl;
        }
    };

protected:
    std::vector<std::unique_ptr<IPlayer>> mPlayers;
};