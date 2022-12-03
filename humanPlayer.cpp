#include "humanPlayer.hpp"

#include <string>
#include <iostream>

std::unique_ptr<Hand> HumanPlayer::PlayHand()
{
    std::string input;

    std::cout << mName << ", please enter your hand: ";
    std::cin >> input;

    return mHandFactory.CreateHandFromString(input);
}