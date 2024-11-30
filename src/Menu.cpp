#include <iostream>
#include <array>
#include "Player.hpp"
#include "Game.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(std::time(0)); // seed generator
    std::setlocale(LC_ALL, ".65001"); // deal with accents
    std::array<char, 10> board{};
    int game_mode {};
    std::cout << "Bienvenue dans le jeu du TicTacToe" << std::endl;
    std::cout << "Veuillez choisir un mode de jeu :" << std::endl;
    std::cout << "1. Deux joueurs" << std::endl;
    std::cout << "2. Un joueur contre l'IA" << std::endl;
    std::cin >> game_mode;
    game_init(board, game_mode);
    return 0;
}