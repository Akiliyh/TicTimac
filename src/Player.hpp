#pragma once
#include <iostream>

namespace Player
{
    struct Player
    {
        std::string name;
        char symbol;
    };

    Player create_player();
}