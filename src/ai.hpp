#pragma once
#include <iostream>
#include <array>
#include "player.hpp"
#include <optional>

namespace AI {

    void plays(std::array<char, 10> &board, int const &round, int &input, Player::Player const &ai, Player::Player const &player);
    int minimax(std::array<char, 10>& board, int depth, bool isMaximizing, Player::Player const &player, Player::Player const &ai, int alpha, int beta);

}