#include "helpers.hpp"

std::string getNameForPlayer(int playerNumber)
{
    std::string name;
    std::cout << "Player " << playerNumber << ", please enter your name: ";
    std::cin >> name;
    return name;
}

void printResult(Result result, const std::string_view player1, const std::string_view player2)
{
    if (result.GetActionName())
    {
        std::cout << player1 << " " << result.GetActionName().value() << " " << player2 << std::endl;
        return;
    }

    switch (result.GetAction())
    {
    case 0:
        std::cout << player1 << " draws against " << player2 << "!" << std::endl;
        break;
    case 1:
        std::cout << player1 << " wins against " << player2 << "!" << std::endl;
        break;
    case -1:
        std::cout << player2 << " wins against " << player1 << "!" << std::endl;
        break;
    default:
        throw std::runtime_error("Invalid result");
    }
}

void printBreakLine()
{
    std::cout << "----------------------------------------" << std::endl;
}
