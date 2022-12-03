#pragma once

#include "IRound.hpp"
#include "IHandFactory.hpp"
#include "IPlayer.hpp"
#include "boost/format.hpp"

class IGame
{
public:
    IGame(){};
    virtual void Setup() = 0;
    virtual void Play() = 0;
    virtual void PrintScores()
    {
        std::cout << boost::format("%-10s | %s") % "Player" % "Score" << std::endl;
        for (auto &player : mPlayers)
        {
            std::cout << boost::format("%-10s | %d") % player->GetName() % player->GetScore() << std::endl;
        }
    };

protected:
    std::vector<std::unique_ptr<IPlayer>> mPlayers;
};