// ////////////////////////////////////////////////////////
//
// Author: Jared Lipkin
//
// Header file for CLParser class. Responsible for
// parsing user input to identify player name and any
// optional arguments.
//
// ////////////////////////////////////////////////////////

#ifndef CL_PARSE_H
#define CL_PARSE_H

#include "game.h"

#include <vector>
#include <string>

class CLParser {
    private:
        int argc;
        std::vector<std::string> argv;

        // Game info --> results of parsing
        std::string m_player_name;
        Game::mode m_mode;
        int m_generator_count;

        // helper members
        bool h = false;
        bool s = false;
        bool t = false;
        bool g = false;

        // helper functions
        void evaluate_bools();
        void validate_bools();

        // setter functions
        void set_game_mode();
        void set_player_name();
        void set_generator_count();

    public:
        CLParser(int count, char *args[]);

        void parse_command_line();

        // getter functions
        std::string get_player_name() { return m_player_name; }
        Game::mode get_game_mode() { return m_mode; }
        int get_generator_count() { return m_generator_count; }
};

#endif