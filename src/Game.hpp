#pragma once
#include "Player.hpp"
#include <optional>

void game_init(std::array<char, 10> &board, int game_mode);
void game(std::array<char, 10> &board, Player::Player &player1, Player::Player &player2);
void draw_game_board(std::array<char, 10> &board);
bool is_game_over(std::array<char, 10> const &board);
std::optional<Player::Player> check_winner(std::array<char, 9> const &board, Player::Player const &player1, Player::Player const &player2);
void draw_example_board();
