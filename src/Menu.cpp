#include <iostream>
#include <vector>
#include "player.hpp"
#include "game.hpp"
#include "ai.hpp"
#include <cstdlib>
#include <ctime>
#include <limits>
#include "verification.hpp"
#include "terminal_ctrl.hpp"

int main()
{
    std::srand(std::time(0));         // seed generator
    std::setlocale(LC_ALL, ".65001"); // deal with accents
    int grid_size {3};
    std::vector<char> board((grid_size*grid_size+1), '.');
    int game_mode{};
    terminal_ctrl::clear_screen();
    terminal_ctrl::set_background_color(terminal_ctrl::ColorCode::BLACK); // and why not
    terminal_ctrl::set_text_color(terminal_ctrl::ColorCode::WHITE);
    terminal_ctrl::set_font_style(terminal_ctrl::FontStyle::BOLD);
    std::cout << "Bienvenue dans le jeu du Morpiong" << std::endl;
    
    // flag
    terminal_ctrl::set_background_color(terminal_ctrl::ColorCode::BLUE);
    std::cout << " ";
    terminal_ctrl::set_background_color(terminal_ctrl::ColorCode::WHITE);
    std::cout << " ";
    terminal_ctrl::set_background_color(terminal_ctrl::ColorCode::RED);
    std::cout << " " << std::endl; 

    terminal_ctrl::set_background_color(terminal_ctrl::ColorCode::BLACK);
    std::cout << std::endl;
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

    game_init(board, game_mode, grid_size);
    return 0;
}