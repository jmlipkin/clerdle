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
#include <string>
#include <exception>
#include <stdexcept>

Game create_game(const CLParser &parse);

int main(int argc, char* argv[])
{
    // Initializing the data
    CLParser parse{argc, argv};
    // Parsing the command line, with validation 
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
    Game my_game = create_game(parse);
    try
    {
        my_game.play();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return -1;
    }
    return 0;
}

// Creates a game object given properties determined by input parsing
Game create_game(const CLParser &parse)
{
    // Fetching game settings from CL Parser
    std::string player_name = parse.get_player_name();
    Game::mode mode = parse.get_game_mode();
    int gen_count = parse.get_generator_count();

    // Creating and running the game
    Game my_game{player_name, mode, gen_count};
    return my_game;
}