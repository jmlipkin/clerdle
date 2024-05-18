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
        std::string m_player_name = "NO NAME";
        int m_gen_count = 0;

        void evaluate_bools(bool &h, bool &s, bool &t, bool &g);
        void set_player_name();
        void set_generator_count();

    public:
        CLParser(int count, char *args[]);
        Game::mode parse_command_line();
        std::string get_player_name();
        int get_generator_count();
};

#endif