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

#include <vector>
#include <string>

class CLParser {
    private:
        int argc;
        std::vector<std::string> argv;
        std::string m_player_name = "NO NAME";

        void set_player_name();

    public:
        CLParser(int count, char *args[]);
        std::string get_player_name();
        void parse_command_line();
};

#endif