#pragma once
#include <iostream>

namespace Player
{
    struct Player
    {
        std::string name;
        char symbol;
        int wins;
    };

    Player create_player();
}