#pragma once

#include "interface/ITwoPlayerRound.hpp"
#include "interface/INPlayerRound.hpp"

class Round : public ITwoPlayerRound
{
public:
    Round(std::vector<std::unique_ptr<IPlayer>> &players) : ITwoPlayerRound(players){};
    void Play() override;
};

class NPlayerRound : public INPlayerRound
{
public:
    NPlayerRound(std::vector<std::unique_ptr<IPlayer>> &players) : INPlayerRound(players){};
    void Play() override;
};