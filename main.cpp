#include <iostream>
#include "handFactory.hpp"
#include "paper.hpp"
#include "scissors.hpp"
#include "rock.hpp"
#include "botPlayer.hpp"
#include "humanPlayer.hpp"

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

std::string getNameForPlayer(int playerNumber)
{
    std::string name;
    std::cout << "Player " << playerNumber << ", please enter your name: ";
    std::cin >> name;
    return name;
}

int main(int, char **)
{
    auto handFactory = HandFactory{};
    auto player1 = HumanPlayer{getNameForPlayer(1), handFactory};
    auto player2 = BotPlayer{handFactory};

    for (auto i = 0; i < 3; ++i)
    {
        auto player1Hand = player1.PlayHand();
        auto player2Hand = player2.PlayHand();
        std::cout << player1.GetName() << " played " << player1Hand->GetName() << std::endl;
        std::cout << player2.GetName() << " played " << player2Hand->GetName() << std::endl;

        auto result = player1Hand->PlayAgainst(*player2Hand);
        printResult(result, player1.GetName(), player2.GetName());
    }
}