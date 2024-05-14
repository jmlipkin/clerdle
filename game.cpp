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
