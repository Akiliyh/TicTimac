#include <iostream>
#include "ai.hpp"
#include <array>
#include <limits>
#include <optional>
#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>
#include <vector>
#include "verification.hpp"

namespace AI
{

    int minimax(std::vector<char> &board, int depth, bool isMaximizing, Player::Player const &player, Player::Player const &ai, int alpha, int beta, int grid_size)
    {
        auto winner = Verif::check_winner(board, player, ai, grid_size);
        if (winner.has_value())
        {
            if (winner.value().symbol == ai.symbol) return 10 - depth; // AI wins
            if (winner.value().symbol == player.symbol) return depth - 10; // player wins
        }

        if (std::all_of(board.begin() + 1, board.end(), [](char c) { return c != '.'; })) // check 
        {
            return 0;
        }

        if (depth == 0) return 0;
        if (isMaximizing)
        {
            int maxEval = std::numeric_limits<int>::min(); // −∞
            for (int i = 1; i < 10; i++)
            {
                if (board[i] == '.')
                {
                    board[i] = ai.symbol; // Simulate AI move
                    int eval = minimax(board, depth - 1, false, player, ai, alpha, beta, grid_size);
                    board[i] = '.'; // Undo move
                    maxEval = std::max(maxEval, eval);
                    if (maxEval > beta)
                    {
                        break;
                    }
                    alpha = std::max(alpha, maxEval);
                    
                }
            }
            return maxEval;
        }
        else
        {
            int minEval = std::numeric_limits<int>::max(); // +∞
            for (int i = 1; i < 10; i++)
            {
                if (board[i] == '.')
                {
                    board[i] = player.symbol; // Simulate Player move
                    int eval = minimax(board, depth - 1, true, player, ai, alpha, beta, grid_size);
                    board[i] = '.'; // Undo move
                    minEval = std::min(minEval, eval);
                    if (minEval < alpha)
                    {
                        break;
                    }
                    beta = std::min(beta, minEval);
                }
            }
            return minEval;
        }
    }

    void plays(std::vector<char> &board, int const &round, int &input, Player::Player const &ai, Player::Player const &player, int grid_size) // add later the difficulty parameter
    {
        std::array<int, 4> corners{1, grid_size, grid_size*grid_size-grid_size+1, grid_size*grid_size};
        int randomCorners = std::rand() % 4;
        std::cout << minimax(board, 10, true, player, ai, std::numeric_limits<int>::min(), std::numeric_limits<int>::max(), grid_size) << std::endl;
        if (round == 1) // best to pick corners at first, source: wikihow
            input = corners[randomCorners];
        else
        {
            int bestMove = -1;
            int bestValue = std::numeric_limits<int>::min(); // −∞

            for (int i = 1; i < 10; i++)
            {
                if (board[i] == '.')
                {
                    board[i] = ai.symbol; // Simulate AI move
                    int moveValue = minimax(board, 10, false, player, ai, std::numeric_limits<int>::min() , std::numeric_limits<int>::max(), grid_size); // Start Minimax
                    board[i] = '.'; // Undo move
                    std::cout << moveValue << std::endl;
                    if (moveValue > bestValue)
                    {
                        bestValue = moveValue;
                        bestMove = i;
                    }
                }
            }
            std::cout << bestMove << std::endl;
            input = bestMove;
        }
    }
}
