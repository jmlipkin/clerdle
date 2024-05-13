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
        std::string get_name(void) { return m_name; }
        std::vector<int> get_game_data(void) { return m_game_data; }
};
#endif