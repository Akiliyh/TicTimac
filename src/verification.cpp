#include "verification.hpp"

namespace Verif
{

    std::optional<Player::Player> check_winner(std::vector<char> const &board, Player::Player const &player1, Player::Player const &player2, int grid_size)
    {
        Player::Player winner{};
        for (int j = (grid_size*grid_size)-grid_size+1; j > 0; j -= grid_size)
        {
            // horizontal check
            if (board[j] != '.' && board[j] == board[j + 1] && board[j] == board[j + 2])
            {
                board[j] == player1.symbol ? winner = player1 : winner = player2;
                return winner;
            }

            // vertical check

            for (int i = 0; i < grid_size; i++)
            {
                if (board[i + grid_size*2 +1] != '.' && board[i + grid_size*2 +1] == board[i + grid_size +1] && board[i + grid_size*2+1] == board[i+1])
                {
                    board[i + grid_size*2 +1] == player1.symbol ? winner = player1 : winner = player2;
                    return winner;
                }

                // diagonals
                if (board[grid_size] != '.' && board[grid_size] == board[grid_size+grid_size-1] && board[grid_size] == board[(grid_size+grid_size-1)+grid_size-1])
                {
                    board[grid_size] == player1.symbol ? winner = player1 : winner = player2;
                    return winner;
                }
                if (board[i] != '.' && board[i+j] == board[i+grid_size+1] && board[i] == board[(i+grid_size+1)+grid_size+1])
                {
                    board[i] == player1.symbol ? winner = player1 : winner = player2;
                    return winner;
                }
            }
        }

        // no winner, either game not over or draw
        return std::nullopt;
    }
} // namespace Verif