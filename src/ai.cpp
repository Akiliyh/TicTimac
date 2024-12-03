#include <iostream>
#include "ai.hpp"
#include <array>
#include <limits>
#include <optional>

namespace AI
{
    void plays(std::array<char, 10> &board, int const &round, int &input) // add later the difficulty parameter
    {
        std::array<int, 4> corners{1, 3, 7, 9};
        int randomCorners = std::rand() % 4;
        if (round == 1)
            input = corners[randomCorners];
        else if (round == 2 && board[5] == '.')
            input = 5;
        else if (round == 2 && board[corners[randomCorners]] == '.')
            input = corners[randomCorners];
        else
        {
            do
            {
                input = (std::rand() % 9) + 1;
            } while (board[input] != '.');
        }
    }
}
