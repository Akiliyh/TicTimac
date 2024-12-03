#include <iostream>
#include <array>
#include "player.hpp"
#include "game.hpp"
#include "ai.hpp"
#include <cstdlib>
#include <ctime>
#include <limits>

int main()
{
    std::srand(std::time(0));         // seed generator
    std::setlocale(LC_ALL, ".65001"); // deal with accents
    std::array<char, 10> board{};
    int game_mode{};
    std::cout << "Bienvenue dans le jeu du TicTacToe" << std::endl;
    std::cout << "Veuillez choisir un mode de jeu :" << std::endl;
    std::cout << "1. Deux joueurs" << std::endl;
    std::cout << "2. Un joueur contre l'IA" << std::endl;
    // prevent mistakes
    while (true)
    {
        std::cin >> game_mode;
        if (std::cin.fail() || game_mode > 2 || game_mode < 1)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard
            std::cout << "Hey c'est pas valide ! Donne soit 1 ou 2." << std::endl;
            continue;
        }
        break;
    }

    game_init(board, game_mode);
    return 0;
}