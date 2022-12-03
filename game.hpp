#pragma once

#include <vector>

#include "interface/IGame.hpp"
#include "interface/IPlayer.hpp"
#include "humanPlayer.hpp"
#include "botPlayer.hpp"

template <class Round, class HandFactory>
class PlayerVsBotGame : public IGame
{
public:
    PlayerVsBotGame() : mHandFactory(HandFactory{}){};
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

template <class Round, class HandFactory>
class BotVsBotGame : public IGame
{
public:
    BotVsBotGame() : mHandFactory(HandFactory{}){};
    void Setup() override
    {
        mPlayers.push_back(std::make_unique<BotPlayer>("PC1", mHandFactory));
        mPlayers.push_back(std::make_unique<BotPlayer>("PC2", mHandFactory));

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, 10);

        std::cout << "Picking random number of rounds... ";
        mNumRounds = dis(gen);
        std::cout << "Playing " << mNumRounds << " rounds" << std::endl;
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