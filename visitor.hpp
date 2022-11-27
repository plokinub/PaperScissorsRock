#pragma once

#include "scissors.hpp"
#include "paper.hpp"
#include "rock.hpp"

class Visitor
{
public:
    int Play(Paper &paper);
    int Play(Scissors &scissors);
    int Play(Rock &rock);
};