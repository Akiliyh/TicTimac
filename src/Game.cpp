// #include <terminal_ctrl/terminal_ctrl.h>
#include <iostream>
#include "Player.hpp"
#include <array>
#include <limits>

void draw_example_board(std::array<char, 9> const board)
{
    for (int j = 7; j > 0; j -= 3)
    {
        std::cout << '|';
        for (int i = 0; i < 3; i++)
        {
            std::cout << j + i << '|';
        }
        std::cout << std::endl;
    }
}

// not optimized
bool is_game_over(std::array<char, 9> const &board)
{
    bool gameOver{false};
    for (int j = 7; j > 0; j -= 3) // starts at 6 cause it's an array and starts at 0 we'll add the +1 after for the numpad transcription
    {
            if (board[j] == board[j + 1] && board[j] == board[j + 2])
            {
                if (board[j] != '.') return gameOver = true;
            }

            for (size_t i = 0; i < board.size() / 3; i++)
            {
                if (board[i+7 ] == board[i+7 - 3] && board[i+7] == board[i+7 - 6])
                {
                    if (board[i] != '.' && board[j] != '.') return gameOver = true;
                }

                // diagonals
                if (board[7 ] == board[5] && board[7] == board[3])
                {
                    if (board[i] != '.' && board[j] != '.') return gameOver = true;
                }
                if (board[1 ] == board[5] && board[1] == board[9])
                {
                    if (board[i] != '.' && board[j] != '.') return gameOver = true;
                }
            }
    }

    return gameOver;
}

void draw_game_board(std::array<char, 9> &board)
{
    for (int j = 7; j > 0; j -= 3) // starts at 6 cause it's an array and starts at 0 we'll add the +1 after for the numpad transcription
    {
        std::cout << '|';
        for (size_t i = 0; i < board.size() / 3; i++)
        {
            if (board[i + j] == '\0')
                board[i + j] = '.';
            std::cout << board[i + j] << '|';
        }
        std::cout << std::endl;
    }
}

void game(std::array<char, 9> &board, Player::Player &player1, Player::Player &player2)
{
    bool isGameOver{false};
    int input{};
    Player::Player plrToPlay{player1};
    (std::rand() % 2 == 0) ? plrToPlay = player1 : plrToPlay = player2;

    while (!isGameOver)
    {
        std::cout << plrToPlay.name << ", c'est à toi de jouer !" << std::endl;
        draw_game_board(board);

        // prevent mistakes

        while (true)
        {
            std::cin >> input;
            if (std::cin.fail() || input < 1 || input > 9)
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard
                std::cout << "Hey c'est pas valide ! Entre un chiffre entre 1 et 9." << std::endl;
                continue;
            }

            if (board[input] != '.')
            {
                std::cout << "Oh non la place est déjà prise réessaye !" << std::endl;
                continue;
            }

            break;
        }

        board[input] = plrToPlay.symbol;
        isGameOver = is_game_over(board);
        (player1.name == plrToPlay.name) ? plrToPlay = player2 : plrToPlay = player1;
    }
    std::cout << "La partie est terminée." << std::endl;
    draw_game_board(board);
}

int main()
{
    std::setlocale(LC_ALL, ".65001"); // deal with accents
    std::array<char, 9> board{};
    // terminal_ctrl::clear_terminal();
    // terminal_ctrl::move_cursor(1, 3);
    draw_example_board(board);
    Player::Player player1{Player::create_player()};
    Player::Player player2{Player::create_player()};
    while (player2.name == player1.name || player2.symbol == player1.symbol)
    {
        std::cout << "Bah non en fait il faut un truc différent. Joueur 2 rename toi." << std::endl;
        player2 = Player::create_player();
    }

    std::cout << "Ton nom joueur 1 c'est ? " << player1.name << std::endl;
    std::cout << "Ton nom joueur 2 c'est ? " << player2.name << std::endl;
    std::cout << "Ton symbole1 ? " << player1.symbol << std::endl;
    std::cout << "Ton symbole2 ? " << player2.symbol << std::endl;
    game(board, player1, player2);

    return 0;
}