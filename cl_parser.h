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

    public:
        CLParser(int count, char *args[]);
};

#endif