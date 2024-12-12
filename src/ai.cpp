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

namespace AI
{

    // create verification cpp file so it's accessible to every file
    std::optional<char> checkWin(const std::array<char, 10>& board)
    {
        const std::array<std::array<int, 3>, 8> winningPositions = {{
            {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, // Rows
            {1, 4, 7}, {2, 5, 8}, {3, 6, 9}, // Columns
            {1, 5, 9}, {3, 5, 7}             // Diagonals
        }};
        
        for (const auto& line : winningPositions)
        {
            if (board[line[0]] != '.' &&
                board[line[0]] == board[line[1]] &&
                board[line[1]] == board[line[2]])
            {
                return board[line[0]]; // Return 'X' or playerSymbol for the winner
            }
        }
        
        // Check for draw
        if (std::all_of(board.begin() + 1, board.end(), [](char c) { return c != '.'; }))
        {
            return 0; // Draw
        }
        
        return std::nullopt; // Game not over
    }

    int minimax(std::array<char, 10>& board, int depth, bool isMaximizing, char const &playerSymbol)
    {
        auto winner = checkWin(board);
        if (winner.has_value())
        {
            if (winner.value() == 'X') return 10 - depth; // AI wins
            if (winner.value() == playerSymbol) return depth - 10; // player wins
            return 0; // Draw
        }

        if (depth == 0) return 0;
        if (isMaximizing)
        {
            int maxEval = std::numeric_limits<int>::min(); // −∞
            for (int i = 1; i < 10; i++)
            {
                if (board[i] == '.')
                {
                    board[i] = 'X'; // Simulate AI move
                    int eval = minimax(board, depth - 1, false, playerSymbol);
                    board[i] = '.'; // Undo move
                    maxEval = std::max(maxEval, eval);
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
                    board[i] = playerSymbol; // Simulate Player move
                    int eval = minimax(board, depth - 1, true, playerSymbol);
                    board[i] = '.'; // Undo move
                    minEval = std::min(minEval, eval);
                }
            }
            return minEval;
        }
    }

    void plays(std::array<char, 10> &board, int const &round, int &input, char const &playerSymbol) // add later the difficulty parameter
    {
        std::array<int, 4> corners{1, 3, 7, 9};
        int randomCorners = std::rand() % 4;
        std::cout << minimax(board, 10, true, playerSymbol) << std::endl;
        if (round == 1)
            input = corners[randomCorners];
        else
        {
            int bestMove = -1;
            int bestValue = std::numeric_limits<int>::min(); // −∞

            for (int i = 1; i < 10; i++)
            {
                if (board[i] == '.')
                {
                    board[i] = 'X'; // Simulate AI move
                    int moveValue = minimax(board, 10, false, playerSymbol); // Start Minimax
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
        // else if (round == 2 && board[5] == '.')
        //     input = 5;
        // else if (round == 2 && board[corners[randomCorners]] == '.')
        //     input = corners[randomCorners];
        // // else {
        // //     minimax(board, 3, true);
        // //     std::cout << minimax(board, 3, true) << std::endl;
        // // }
        // else
        // {
        //     do
        //     {
        //         // input = (std::rand() % 9) + 1;
        //         minimax(board, 10, true);
        //         std::cout << minimax(board, 10, true) << std::endl;
        //     } while (board[input] != '.');
        // }
    }
}
