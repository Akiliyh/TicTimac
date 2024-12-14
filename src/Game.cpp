// #include <terminal_ctrl/terminal_ctrl.h>
#include <iostream>
#include "game.hpp"
#include "ai.hpp"
#include <array>
#include <limits>
#include <optional>
#include "verification.hpp"

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
    int round{1};
    int input{};
    Player::Player plrToPlay = std::rand() % 2 ? player1 : player2;

    while (!isGameOver)
    {
        std::cout << "Tour " << round << std::endl;
        std::cout << plrToPlay.name << ", c'est à toi de jouer !" << std::endl;
        draw_game_board(board);

        if (plrToPlay.name == "AI")
        {
            AI::plays(board, round, input, player1, player2);
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
        round++;
        (player1.name == plrToPlay.name) ? plrToPlay = player2 : plrToPlay = player1;
        // if (round > 5) isGameOver = is_game_over(board); 
        if (round > 5 ) // only check if it's over after fastest win possible i.e. in 5 moves.
        {
            std::optional<Player::Player> winner = Verif::check_winner(board, player1, player2);
            if (winner.has_value()) isGameOver = true;
        }
        if (round > 9) // automatically ends when draw i.e. when all spots are take 3*3=9
        {
            isGameOver = true;
        }
        
    }
    std::cout << "La partie est terminée." << std::endl;
    draw_game_board(board);
    std::optional<Player::Player> winner = Verif::check_winner(board, player1, player2);
    if (winner.has_value())
    {
        std::cout << "Le gagnant est " << winner.value().name << std::endl;
        player1.name == winner.value().name ? player1.wins++ : player2.wins++;
        std::cout << "Le head to head est pour l'instant de " << std::endl;
        std::cout << player1.name << " " << player1.wins << " / " << player2.name << " " << player2.wins << std::endl;
    } else {
        std::cout << "La partie est bien nulle." << std::endl;
    }
    
    std::cout << "Voulez-vous recommencer ?" << std::endl;
    std::cout << "1. Oui" << std::endl;
    std::cout << "2. Non ton jeu est nul." << std::endl;
    int replay_input{};
    // prevent mistakes
    while (true)
    {
        std::cin >> replay_input;
        if (std::cin.fail() || replay_input > 2 || replay_input < 1)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard
            std::cout << "Hey c'est pas valide ! Donne soit 1 ou 2." << std::endl;
            continue;
        }
        break;
    }
    if(replay_input == 1) replay_game(player1, player2);
    else std::cout << "Bah super" << std::endl;
}

void replay_game(Player::Player &player1, Player::Player &player2)
{
    // restart the board
    std::array<char, 10> board{};
    game(board, player1, player2);
}

void game_init(std::array<char, 10> &board, int game_mode)
{
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