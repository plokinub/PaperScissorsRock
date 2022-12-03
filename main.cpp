#include <iostream>
#include "handFactory.hpp"
#include "paper.hpp"
#include "scissors.hpp"
#include "rock.hpp"
#include "botPlayer.hpp"
#include "humanPlayer.hpp"
#include "helpers.hpp"
#include "game.hpp"
#include "round.hpp"

int main(int, char **)
{
    auto game = NPlayerBotGame<NPlayerRound, HandFactory>{};
    game.Setup();
    game.Play();
    game.PrintScores();
}