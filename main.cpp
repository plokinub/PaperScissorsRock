#include <iostream>
#include "handFactory.hpp"

int main(int, char **)
{
    auto handFactory = HandFactory();
    auto rock = handFactory.CreateRock();
    auto paper = handFactory.CreatePaper();
    auto scissors = handFactory.CreateScissors();

    std::cout << "Rock vs Paper: " << rock->PlayAgainst(*paper) << std::endl;
    std::cout << "Rock vs Scissors: " << rock->PlayAgainst(*scissors) << std::endl;
    std::cout << "Rock vs Rock: " << rock->PlayAgainst(*rock) << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    std::cout << "Paper vs Rock: " << paper->PlayAgainst(*rock) << std::endl;
    std::cout << "Paper vs Scissors: " << paper->PlayAgainst(*scissors) << std::endl;
    std::cout << "Paper vs Paper: " << paper->PlayAgainst(*paper) << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    std::cout << "Scissors vs Rock: " << scissors->PlayAgainst(*rock) << std::endl;
    std::cout << "Scissors vs Paper: " << scissors->PlayAgainst(*paper) << std::endl;
    std::cout << "Scissors vs Scissors: " << scissors->PlayAgainst(*scissors) << std::endl;
}