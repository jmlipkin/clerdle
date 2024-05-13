// ////////////////////////////////////////////////////////
//
// Author: Jared Lipkin
//
// Header file for PlayerStats class. Responsible for
// manipulating individual player data.
//
// ////////////////////////////////////////////////////////

#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
    private:
        std::string m_name;
        // TODO: add game information
    public:

        std::string to_string(void);
};

#endif