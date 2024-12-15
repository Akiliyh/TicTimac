#include "verification.hpp"

namespace Verif
{

    std::optional<Player::Player> check_winner(std::vector<char> const &board, Player::Player const &player1, Player::Player const &player2, int grid_size)
    {
        Player::Player winner{};
        for (int j = (grid_size*grid_size)-grid_size+1; j > 0; j -= grid_size)
        {
            if (board[j] != '.' && board[j] == board[j + 1] && board[j] == board[j + 2])
            {
                board[j] == player1.symbol ? winner = player1 : winner = player2;
                return winner;
            }

            for (size_t i = 0; i < board.size() / grid_size; i++)
            {
                if (board[i + 7] != '.' && board[i + 7] == board[i + 7 - 3] && board[i + 7] == board[i + 7 - 6])
                {
                    board[i + 7] == player1.symbol ? winner = player1 : winner = player2;
                    return winner;
                }

                // diagonals
                if (board[7] != '.' && board[7] == board[5] && board[7] == board[3])
                {
                    board[7] == player1.symbol ? winner = player1 : winner = player2;
                    return winner;
                }
                if (board[1] != '.' && board[1] == board[5] && board[1] == board[9])
                {
                    board[1] == player1.symbol ? winner = player1 : winner = player2;
                    return winner;
                }
            }
        }

        // no winner, either game not over or draw
        return std::nullopt;
    }
} // namespace Verif