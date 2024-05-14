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
    try
    {
        switch (m_mode)
        {
            case normal:
                normal_gameplay();
                break;
            case allstats:
                my_players.get_all_stats();
                break;
            case playerstats:
                my_players.get_player(m_player_name).get_histogram();
                break;
            case test:
                // TODO: puzzle.show_solution();
                normal_gameplay();
                break;
            case generate:
                generate_mode();
                break;
            case missing_player:
                missing_player_mode();
                break;
            case play_with_help:
                display_usage();
                normal_gameplay();
                break;
            default:
                display_usage();
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

// TODO
void Game::normal_gameplay()
{}

// TODO: add no-quotes, no commas validation
void Game::missing_player_mode()
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
    normal_gameplay();
}

// TODO: Fix generate cl entry
void Game::generate_mode()
{
    // TODO
}