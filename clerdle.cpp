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

#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>

int main(int argc, char* argv[])
{
    // Just setting up!
    PlayerCollection my_players{};
    CLParser parse{argc, argv};
    try
    {
        parse.parse_command_line();
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << e.what() << '\n';
        return -1;
    }
    std::string player_name = parse.get_player_name();

    return 0;
}