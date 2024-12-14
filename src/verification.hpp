#pragma once
#include "player.hpp"
#include <optional>
#include <iostream>
#include <array>

namespace Verif
{
    std::optional<Player::Player> check_winner(std::array<char, 10> const &board, Player::Player const &player1, Player::Player const &player2);
} // namespace Verif
