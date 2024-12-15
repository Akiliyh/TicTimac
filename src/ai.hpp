#pragma once
#include <iostream>
#include <vector>
#include "player.hpp"
#include <optional>

namespace AI {

    void plays(std::vector<char> &board, int const &round, int &input, Player::Player const &ai, Player::Player const &player, int grid_size);
    int minimax(std::vector<char>& board, int depth, bool isMaximizing, Player::Player const &player, Player::Player const &ai, int alpha, int beta, int grid_size);

}