#pragma once

#include "IPlayer.hpp"
#include "IRound.hpp"

#include <vector>

#include <concepts>

class INPlayerRound : public IRound
{
public:
    INPlayerRound(std::vector<std::unique_ptr<IPlayer>> &players) : IRound(players){};
};

template <typename RoundType>
concept IsNPlayerRound = std::derived_from<RoundType, INPlayerRound>;