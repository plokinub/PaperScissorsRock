#include "round.hpp"

#include <iostream>
#include "helpers.hpp"

void Round::Play()
{
    auto &player1 = mPlayers.at(0);
    auto &player2 = mPlayers.at(1);

    auto player1Hand = player1->PlayHand();
    auto player2Hand = player2->PlayHand();
    std::cout << player1->GetName() << " played " << player1Hand->GetName() << ". " << player2->GetName() << " played " << player2Hand->GetName() << std::endl;

    auto result = player1Hand->PlayAgainst(*player2Hand);
    printResult(result, player1->GetName(), player2->GetName());
}