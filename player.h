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
#include <vector>

class Player {
    private:
        std::string m_name;
        std::vector<int> m_game_data;
    public:
        Player(std::string name, std::vector<int> game_data);
        std::string to_string(void);
};

#endif