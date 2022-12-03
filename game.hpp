#pragma once

#include <vector>

#include "interface/IGame.hpp"
#include "interface/IPlayer.hpp"
#include "humanPlayer.hpp"
#include "botPlayer.hpp"

template <class Round, class HandFactory>
class Game : public IGame
{
public:
    Game() : mHandFactory(HandFactory{}){};
    void Setup() override
    {
        mPlayers.emplace_back(std::make_unique<HumanPlayer>(getNameForPlayer(1), mHandFactory));
        mPlayers.push_back(std::make_unique<BotPlayer>(mHandFactory));

        std::cout << "How many rounds do you want to play? ";
        std::cin >> mNumRounds;
    };
    void Play() override
    {
        auto round = Round(mPlayers);
        for (int i = 0; i < mNumRounds; ++i)
        {
            round.Play();
        }
    };

protected:
    HandFactory mHandFactory;
    std::vector<std::unique_ptr<IPlayer>> mPlayers;
    int mNumRounds = 1;
};