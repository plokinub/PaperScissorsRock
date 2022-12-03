#include "round.hpp"

#include <iostream>
#include <memory>
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

    if (result == 1)
    {
        player1->AddWin();
    }
    else if (result == -1)
    {
        player2->AddWin();
    }
    printBreakLine();
}

void NPlayerRound::Play()
{
    std::vector<std::unique_ptr<Hand>> hands;
    printBreakLine();
    for (const auto &player : mPlayers)
    {
        hands.emplace_back(player->PlayHand());
        std::cout << player->GetName() << " played " << hands.back()->GetName() << std::endl;
    }
    printBreakLine();
    for (auto player1It = mPlayers.begin(); player1It != mPlayers.end(); ++player1It)
    {

        for (auto player2It = player1It + 1; player2It != mPlayers.end(); ++player2It)
        {
            auto &player1 = *player1It;
            auto &player2 = *player2It;
            auto &player1Hand = hands.at(std::distance(mPlayers.begin(), player1It));
            auto &player2Hand = hands.at(std::distance(mPlayers.begin(), player2It));
            auto result = player1Hand->PlayAgainst(*player2Hand);

            if (result == 1)
            {
                player1->AddWin();
            }
            else if (result == -1)
            {
                player2->AddWin();
            }

            printResult(result, player1->GetName(), player2->GetName());
        }
    }
}