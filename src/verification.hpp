#pragma once
#include "player.hpp"
#include <optional>
#include <iostream>
#include <vector>

namespace Verif
{
    std::optional<Player::Player> check_winner(std::vector<char> const &board, Player::Player const &player1, Player::Player const &player2, int grid_size);
} // namespace Verif
