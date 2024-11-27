#include <iostream>
#include "Player.hpp"

namespace Player {

    Player create_player()
    {
        Player player{};
        std::cout << "C'est quoi ton nom min fieu ?" << std::endl;
        std::cin >> player.name;
        std::cout << "Tu veux quel symbole mon frère ?" << std::endl;
        std::cin >> player.symbol;

        return player;

    }
}