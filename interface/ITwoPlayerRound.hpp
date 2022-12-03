#pragma once

#include "IPlayer.hpp"
#include "IRound.hpp"

#include <vector>

#include <concepts>

class ITwoPlayerRound : public IRound
{
public:
    ITwoPlayerRound(std::vector<std::unique_ptr<IPlayer>> &players) : IRound(players){};
};

template <typename RoundType>
concept IsTwoPlayerRound = std::derived_from<RoundType, ITwoPlayerRound>;