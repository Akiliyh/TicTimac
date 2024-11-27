// #include <terminal_ctrl/terminal_ctrl.h>
#include <iostream>
#include "Player.hpp"
#include <array>

void draw_game_board(std::array<char, 9> board)
{
    for (size_t j = 0; j < board.size() / 3; j++)
    {
        std::cout << '|';
        for (size_t i = 0; i < board.size() / 3; i++)
        {
            if (board[i+j] == '\0') board[i+j] = '.';           
            std::cout << board[i+j] << '|';
        }
        std::cout << std::endl; 
    } 
}

int main()
{
    std::setlocale(LC_ALL, ".65001");
    std::array<char, 9> board {};
    // terminal_ctrl::clear_terminal();
    // terminal_ctrl::move_cursor(1, 3);
    Player::Player player1{Player::create_player()};
    Player::Player player2{Player::create_player()};
    while (player2.name == player1.name || player2.symbol == player1.symbol)
    {
        std::cout << "Bah non en fait il faut un truc différent. Joueur 2 rename toi." << std::endl;
        player2 = Player::create_player();
    }

    std::cout << "Ton nom joueur 1 c'est ? " << player1.name << std::endl;
    std::cout << "Ton nom joueur 2 c'est ? " << player2.name << std::endl;
    std::cout << "Ton symbole1 ? " << player1.symbol << std::endl;
    std::cout << "Ton symbole2 ? " << player2.symbol << std::endl;
    draw_game_board(board);

    return 0;
}