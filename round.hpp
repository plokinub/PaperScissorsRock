#pragma once

#include "interface/ITwoPlayerRound.hpp"

class Round : public ITwoPlayerRound
{
public:
    Round(std::vector<std::unique_ptr<IPlayer>> &players) : ITwoPlayerRound(players){};
    void Play() override;
};

class ThreePlayerRound : public IRound
{
public:
    ThreePlayerRound(std::vector<std::unique_ptr<IPlayer>> &players) : IRound(players){};
    void Play() override;
};