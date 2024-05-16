#include "game.h"

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

void Game::display_usage()
{
    using namespace std;
    cout << "Displaying usage..." << endl;
}

void Game::play()
{
    switch (m_mode)
    {
        case normal:
            break;
        case allstats:
            my_players.get_all_stats();
            return;
        case playerstats:
            my_players.get_player_stats(m_player_name);
            return;
        case test:
            // TODO: puzzle.show_solution();
            break;
        case generate:
            generate_mode();
            return;
        case missing_player:
            prompt_for_player();
            break;
        case play_with_help:
            display_usage();
            break;
        default:
            display_usage();
            return;
    }
    normal_gameplay();
}

// TODO
void Game::normal_gameplay()
{
    std::cout << "Entering normal gameplay" << std::endl;
}

// TODO: add no-quotes, no commas validation
void Game::prompt_for_player()
{
    bool valid = false;
    std::string name{};
    std::string args_prefix = "-";
    std::string exe_prefix = ".";
    while (!valid)
    {
        name = "NO NAME";
        std::cout << "Enter a valid name: ";
        std::getline(std::cin, name);
        if (name.rfind(args_prefix, 0) != 0 && name.rfind(exe_prefix, 0) != 0)
        {
            m_player_name = name;
            valid = true;
        }
    }
}

// TODO: Fix generate cl entry
void Game::generate_mode()
{
    // TODO
}