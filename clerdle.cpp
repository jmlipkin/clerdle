// ////////////////////////////////////////////////////////
//
// Author: Jared Lipkin
//
// Command-line port of game Nerdle. My solution to an
// old final project assignment for an introductory
// university C/C++ course.
//
// ////////////////////////////////////////////////////////

#include "player_collection.h"
#include "cl_parser.h"
#include "game.h"

#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <stdexcept>

int main(int argc, char* argv[])
{
    // main block of code
    PlayerCollection my_players{};
    CLParser parse{argc, argv};

    try
    {
        parse.parse_command_line();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        Game::display_usage();
        return -1;
    }

    // Commented out while testing CL_Parser
    std::string player_name = parse.get_player_name();
    Game::mode mode = parse.get_game_mode();
    int gen_count = parse.get_generator_count();

    Game my_game{player_name, mode, gen_count};

    return 0;
}