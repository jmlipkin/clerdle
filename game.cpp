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

Game::Game(std::string player_name, mode mode, int gen_count)
    : m_player_name(player_name), m_mode(mode), m_generator_count(gen_count)
{
    std::cout << "Game mode set to <" << mode_map[m_mode] << ">!" << std::endl;
}

void Game::display_usage()
{
    using namespace std;
    cout << "Displaying usage..." << endl;
}