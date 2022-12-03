#include "helpers.hpp"

std::string getNameForPlayer(int playerNumber)
{
    std::string name;
    std::cout << "Player " << playerNumber << ", please enter your name: ";
    std::cin >> name;
    return name;
}

void printResult(int result, const std::string_view player1, const std::string_view player2)
{
    switch (result)
    {
    case 0:
        std::cout << "It's a tie!" << std::endl;
        break;
    case 1:
        std::cout << player1 << " wins!" << std::endl;
        break;
    case -1:
        std::cout << player2 << " wins!" << std::endl;
        break;
    default:
        throw std::runtime_error("Invalid result");
    }
}

void printBreakLine()
{
    std::cout << "----------------------------------------" << std::endl;
}