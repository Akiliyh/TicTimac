// #include <terminal_ctrl/terminal_ctrl.h>
#include <iostream>
#include "Game.hpp"
#include <array>
#include <limits>
#include <optional>

void draw_example_board()
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

std::optional<Player::Player> check_winner(std::array<char, 10> const &board, Player::Player const &player1, Player::Player const &player2)
{
    Player::Player winner{};
    for (int j = 7; j > 0; j -= 3)
    {
        if (board[j] != '.' && board[j] == board[j + 1] && board[j] == board[j + 2])
        {
            board[j] == player1.symbol ? winner = player1 : winner = player2;
            return winner;
        }

        for (size_t i = 0; i < board.size() / 3; i++)
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

    // if no winner then it's a draw by definition
    return std::nullopt;
}

// not optimized
bool is_game_over(std::array<char, 10> const &board)
{
    bool gameOver{false};
    for (int j = 7; j > 0; j -= 3)
    {
        if (board[j] == board[j + 1] && board[j] == board[j + 2])
        {
            if (board[j] != '.')
                return gameOver = true;
        }

        for (size_t i = 0; i < board.size() / 3; i++)
        {
            if (board[i + 7] == board[i + 7 - 3] && board[i + 7] == board[i + 7 - 6])
            {
                if (board[i + 7] != '.')
                    return gameOver = true;
            }

            // diagonals
            if (board[7] == board[5] && board[7] == board[3])
            {
                if (board[7] != '.')
                    return gameOver = true;
            }
            if (board[1] == board[5] && board[1] == board[9])
            {
                if (board[1] != '.')
                    return gameOver = true;
            }
        }
    }

    // if no winner are defined we check if it's a draw or not

    bool allNonDot = true;
    for (size_t i = 0; i < board.size(); i++)
    {
        if (board[i] == '.')
        {
            allNonDot = false;
            break;
        }
    }

    if (allNonDot)
        return gameOver = true;

    return gameOver;
}

void draw_game_board(std::array<char, 10> &board)
{
    for (int j = 7; j > 0; j -= 3)
    {
        std::cout << '|';
        for (size_t i = 0; i < board.size() / 3; i++)
        {
            if (board[i + j] == '\0') // replace the empty spaces with a dot
                board[i + j] = '.';
            std::cout << board[i + j] << '|';
        }
        std::cout << std::endl;
    }
}

void game(std::array<char, 10> &board, Player::Player &player1, Player::Player &player2)
{
    bool isGameOver{false};
    int input{};
    Player::Player plrToPlay = ((std::rand() % 2) == 0) ? player1 : player2;

    while (!isGameOver)
    {
        std::cout << plrToPlay.name << ", c'est à toi de jouer !" << std::endl;
        draw_game_board(board);

        if (plrToPlay.name == "AI")
        {
            do
            {
                input = (std::rand() % 9) + 1;
            } while (board[input] != '.');
        }
        else
        {
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
        }

        board[input] = plrToPlay.symbol;
        isGameOver = is_game_over(board);
        (player1.name == plrToPlay.name) ? plrToPlay = player2 : plrToPlay = player1;
    }
    std::cout << "La partie est terminée." << std::endl;
    draw_game_board(board);
    check_winner(board, player1, player2).has_value() ? std::cout << "Le gagnant est " << check_winner(board, player1, player2).value().name << std::endl : std::cout << "La partie est nulle en sah." << std::endl;
}

void game_init(std::array<char, 10> &board, int game_mode)
{
    // terminal_ctrl::clear_terminal();
    // terminal_ctrl::move_cursor(1, 3);
    draw_example_board();
    Player::Player player1{};
    if (game_mode == 2)
    {
        player1.name = "AI";
        player1.symbol = 'X';
    }
    else
    {
        player1 = Player::create_player();
    }
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
}