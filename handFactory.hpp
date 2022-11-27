#pragma once

#include "hand.hpp"
#include <memory>

class HandFactory
{

public:
    HandFactory() = default;
    std::unique_ptr<Hand> CreateRock();
    std::unique_ptr<Hand> CreatePaper();
    std::unique_ptr<Hand> CreateScissors();
};