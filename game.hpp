#pragma once

#include <vector>

#include "boost/format.hpp"

#include "interface/IGame.hpp"
#include "interface/ITwoPlayerRound.hpp"
#include "interface/INPlayerRound.hpp"
#include "interface/IPlayer.hpp"
#include "humanPlayer.hpp"
#include "botPlayer.hpp"

template <IsTwoPlayerRound Round, class HandFactory>
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
        printBreakLine();
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
    int mNumRounds = 1;
};

template <IsTwoPlayerRound Round, class HandFactory>
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
        printBreakLine();
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
    int mNumRounds = 1;
};

template <IsNPlayerRound Round, class HandFactory>
class NPlayerBotGame : public IGame
{
public:
    NPlayerBotGame() : mHandFactory(HandFactory{}){};
    void Setup() override
    {
        int numBots;
        std::cout << "How many bots should play? ";
        std::cin >> numBots;

        std::cout << "How many rounds should they play? ";
        std::cin >> mNumRounds;

        printBreakLine();

        for (int i = 0; i < numBots; i++)
        {
            auto name = (boost::format("Bot %d") % i).str();
            mPlayers.push_back(std::make_unique<BotPlayer>(name, mHandFactory));
        }
    };
    void Play() override
    {
        auto round = Round(mPlayers);
        for (int i = 0; i < mNumRounds; ++i)
        {
            round.Play();
        }
        printBreakLine();
    };

protected:
    HandFactory mHandFactory;
    int mNumRounds = 1;
};