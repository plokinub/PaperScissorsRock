#pragma once

#include <string>
#include <iostream>

std::string getNameForPlayer(int playerNumber);

void printResult(int result, const std::string_view player1, const std::string_view player2);

void printBreakLine();
