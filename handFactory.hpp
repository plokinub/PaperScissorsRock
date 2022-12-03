#pragma once

#include "hand.hpp"
#include <memory>

#include "interface/IHandFactory.hpp"

class HandFactory : public IHandFactory
{

public:
    HandFactory() = default;
    std::unique_ptr<Hand> CreateRock();
    std::unique_ptr<Hand> CreatePaper();
    std::unique_ptr<Hand> CreateScissors();
};