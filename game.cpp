#include "game.h"
#include "puzzle.h"
#include "player_collection.h"
#include "player.h"
#include "color.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

const std::vector<std::string> Game::mode_map {
    "usage",
    "allstats",
    "playerstats",
    "test",
    "generate",
    "missing_player",
    "play_with_help",
    "normal"
};

const std::string Game::keyboard_key = "1234567890+-*/=";



Game::Game(std::string player_name, mode mode, int gen_count)
    : m_player_name(player_name), m_mode(mode), m_generator_count(gen_count)
{
    // temporary
    std::cout << "Game mode set to <" << mode_map[m_mode] << ">!" << std::endl;
    m_solution = new Puzzle();
}

Game::~Game()
{
    delete m_solution;
    m_solution = nullptr;
}

void Game::play()
{
    switch (m_mode)
    {
        case allstats:              // DONE
            my_players.display_all_stats();
            return;
        case playerstats:           // DONE
            my_players.display_player_stats(m_player_name);
            return;
        case generate:              // TODO
            // Puzzle::generate_mode(m_generator_count);
            return;
        case test:                  // TODO
            // m_solution.display();
            break;
        case missing_player:        // DONE
            prompt_for_name();
            break;
        case normal:                // DONE
            break;
        default:                    // DONE
            display_usage();
            return;
    }
    normal_game();
}

void Game::normal_game()
{
    // initialize_board();
    // draw_board();
    // draw_keyboard();
    int trial{};
    for (trial = 0; trial < max_tries; trial++)
    {
        std::vector<char> guess = parse_guess();
        if (!Puzzle::is_valid_equation(guess))
        {
            trial--;
            continue;
        }
        update_board(guess, trial);
        update_keyboard(guess);
        draw_board();
        draw_keyboard();
        if (is_solution(guess))
        {
            my_players.update_player_data(m_player_name, trial);
            return;
        }
    }
    my_players.update_player_data(m_player_name, game_over);
}

void Game::prompt_for_name()
{
    bool valid = false;
    std::string name{};
    while (!valid)
    {
        std::cout << "Please enter a valid player name: ";
        name.clear();
        getline(std::cin, name);
        if (Player::is_valid_name(name))
        {
            m_player_name = name;
            valid = true;
        }
    }
}

bool Game::is_solution(const std::vector<char> &guess)
{
    return (guess == m_solution->get_solution());
}
void Game::display_usage()
{
    using namespace std;
    cout << "Usage: " << endl
         << "./clerdle <arguments>" << endl
         << endl
         << "<player> --- Specify name of player. If not given, program" << endl
         << "             will prompt for player name. Name may not be " << endl
         << "             blank or contain commas or double-quotes." << endl
         << endl
         << "Optional arguments:" << endl
         << "-h --------- Displays usage message without returning error." << endl
         << "-t --------- Test mode. If specified, the correct answer is" << endl
         << "             shown." << endl
         << "-s --------- Displays stats. If no user is specified, the " << endl
         << "             statistics for all players are displayed. If " << endl
         << "             -s is specified with <player> (may precede or " << endl
         << "             succeed <player>) that player's statistics will" << endl
         << "             be printed." << endl
         << "-g <number> --- Computes and prints <number> new randomized " << endl
         << "             games and exits the  program." << endl
         << endl 
         << "Note: only one optional argument may be specified at a time."
         << endl << endl
         << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl
         << endl
         << "RULES:" << endl
         << "-- You have 6 tries to guess the puzzle. After each guess," << endl
         << "   the color of the tiles will change to show how close your" << endl
         << "   guess was to the solution." << endl
         << "   - Green -> digit is correct" << endl
         << "   - Pink  -> digit is in the solution but in the wrong spot" << endl
         << "   - If your guess includes, for example, two 1s, but the" << endl
         << "     answer only has one, you will get one colored tile and " << endl
         << "     one black." << endl
         << "-- Each guess is a calculation." << endl
         << "-- You can use any of: [0 1 2 3 4 5 6 7 8 9 0 + - * / =]." << endl
         << "-- The answer will contain exactly one \"=\". No operations" << endl
         << "   will appear to the right of the \"=\"." << endl
         << "-- Standard order of operations applies. Calculate * and / " << endl
         << "   before + and -." << endl
         << endl
         << "Examples:" << endl
         << Color::setFg(Color::white) << Color::setBg(Color::green)
         << "9" << Color::reset() << Color::setFg(Color::white) << "*20=180" << Color::reset() << endl
         << "9 is in the solution and in the correct spot." << endl
         << endl
         << Color::setFg(Color::white)
         << "9*" << Color::setBg(Color::purple) << "2" << Color::reset() << Color::setFg(Color::white)
         << "0=180" << Color::reset() << endl
         << "2 is in the solution but in the wrong spot." << endl
         << endl
         << Color::setFg(Color::white)
         << "9*20=" << Color::setBg(Color::black) << "1" << Color::reset() << Color::setFg(Color::white)
         << "80" << Color::reset() << endl
         << "1 is not in the solution in any spot." << endl
         << endl
         << endl;
}