// #include <terminal_ctrl/terminal_ctrl.h>
#include <iostream>
#include "game.hpp"
#include "ai.hpp"
#include <vector>
#include <limits>
#include <optional>
#include "verification.hpp"
#include "terminal_ctrl.hpp"

void draw_example_board(int grid_size)
{
    for (int j = grid_size * grid_size; j > 0; j -= grid_size)
    {
        std::cout << '|';
        for (int i = 0; i < grid_size; i++)
        {
            std::cout << (j - grid_size + 1) + i << '|'; 
        }
        std::cout << std::endl;
    }
}

void draw_game_board(std::vector<char> &board, int grid_size, Player::Player &player1, Player::Player &player2)
{
    for (int j = grid_size * grid_size; j > 0; j -= grid_size)
    {
        std::cout << '|';
        for (size_t i = 0; i < board.size() / grid_size; i++)
        {
            // apply colors for each player
            if (board[(j - grid_size + 1) + i] == player1.symbol)
            terminal_ctrl::set_background_color(terminal_ctrl::ColorCode::BLUE);
            if (board[(j - grid_size + 1) + i] == player2.symbol)
            terminal_ctrl::set_background_color(terminal_ctrl::ColorCode::RED);
            std::cout << board[(j - grid_size + 1) + i];
            terminal_ctrl::set_background_color(terminal_ctrl::ColorCode::BLACK);
            std::cout << '|';
        }
        std::cout << std::endl;
    }
}

void game(std::vector<char> &board, Player::Player &player1, Player::Player &player2, int grid_size)
{
    bool isGameOver{false};
    int round{1};
    int input{};
    Player::Player plrToPlay = std::rand() % 2 ? player1 : player2;

    while (!isGameOver)
    {   
        terminal_ctrl::clear_screen();
        std::cout << "Pour rappel "<< std::endl;
        draw_example_board(grid_size);
        std::cout << "Tour " << round << std::endl;
        std::cout << plrToPlay.name << ", c'est à toi de jouer !" << std::endl;
        draw_game_board(board, grid_size, player1, player2);

        if (plrToPlay.name == "AI")
        {
            AI::plays(board, round, input, player1, player2, grid_size);
        }
        else
        {
        // prevent mistakes
            while (true)
            {
                std::cin >> input;
                if (std::cin.fail() || input < 1 || input > grid_size*grid_size)
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard
                    std::cout << "Hey c'est pas valide ! Entre un chiffre entre 1 et " << grid_size*grid_size << "." << std::endl;
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
        if (round > 5 ) // only check if it's over after fastest win possible i.e. in 5 moves.
        {
            std::optional<Player::Player> winner = Verif::check_winner(board, player1, player2, grid_size);
            if (winner.has_value()) isGameOver = true;
        }
        if (round > grid_size*grid_size) // automatically ends when draw i.e. when all spots are taken 3*3=9 or grid_size*grid_size
        {
            isGameOver = true;
        }
        
    }
    terminal_ctrl::clear_screen();
    std::cout << "La partie est terminée." << std::endl;
    draw_game_board(board, grid_size, player1, player2);
    std::optional<Player::Player> winner = Verif::check_winner(board, player1, player2, grid_size);
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
    if(replay_input == 1) replay_game(player1, player2, grid_size);
    else std::cout << "Bah super" << std::endl;
}

void replay_game(Player::Player &player1, Player::Player &player2, int grid_size)
{
    // restart the board
    std::vector<char> board((grid_size*grid_size+1), '.');
    game(board, player1, player2, grid_size);
}

void game_init(std::vector<char> &board, int game_mode, int grid_size)
{
    std::cout << "Pour jouer, regarde ton pavé numérique !" << std::endl;
    draw_example_board(grid_size);
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

    std::cout << "Le joueur 1 s'appelle  " << player1.name << std::endl;
    std::cout << "Le joueur 2 s'appelle  " << player2.name << std::endl;
    std::cout << "Le symbole de "<< player1.name << " est " << player1.symbol << std::endl;
    std::cout << "Le symbole de "<< player2.name << " est " << player2.symbol << std::endl;
    game(board, player1, player2, grid_size);
}