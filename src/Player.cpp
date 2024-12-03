#include <iostream>
#include "player.hpp"

namespace Player {

    Player create_player()
    {
        Player player{};
        std::string input;
        std::cout << "C'est quoi ton prénom ?" << std::endl;
        std::cin >> player.name;
        std::cout << "Tu veux quel symbole ?" << std::endl;

        std::cin >> input;
        if (input.size() > 1) std::cout << "Tu veux trop être différent, on va prendre ta première lettre alors." << std::endl;
        player.symbol = input[0]; // only take first char

        return player;

    }
}