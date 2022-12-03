#pragma once

#include "interface/IRound.hpp"

class Round : public IRound
{
public:
    Round(std::vector<std::unique_ptr<IPlayer>> &players) : IRound(players){};
    void Play() override;
};