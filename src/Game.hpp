#pragma once
#include "player.hpp"
#include <vector>
#include <optional>

void game_init(std::vector<char> &board, int game_mode, int grid_size);
void game(std::vector<char> &board, Player::Player &player1, Player::Player &player2, int grid_size);
void draw_game_board(std::vector<char> &board, int grid_size, Player::Player &player1, Player::Player &player2);
void draw_example_board(int grid_size);
void replay_game(Player::Player &player1, Player::Player &player2, int grid_size);
