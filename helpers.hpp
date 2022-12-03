#pragma once

#include <string>
#include <iostream>

#include "action.hpp"

std::string getNameForPlayer(int playerNumber);

void printResult(Result result, const std::string_view player1, const std::string_view player2);

void printBreakLine();
