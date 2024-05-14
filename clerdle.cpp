// ////////////////////////////////////////////////////////
//
// Author: Jared Lipkin
//
// Command-line port of game Nerdle. My solution to an
// old final project assignment for an introductory
// university C/C++ course.
//
// ////////////////////////////////////////////////////////

#include "cl_parser.h"
#include "game.h"

#include <iostream>
#include <exception>
#include <stdexcept>

int main(int argc, char* argv[])
{
    // Just setting up!
    CLParser parse{argc, argv};
    Game::mode mode{Game::usage};
    try
    {
        mode = parse.parse_command_line();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        Game::display_usage();
        return -1;
    }
    std::string player_name = parse.get_player_name();

    Game my_game{player_name, mode};
    my_game.play();

    return 0;
}