// ////////////////////////////////////////////////////////
//
// Author: Jared Lipkin
//
// Source file for PlayerStats class. Responsible for
// manipulating individual player data.
//
// ////////////////////////////////////////////////////////

#include "player.h"

#include <string>
#include <sstream>

std::string Player::to_string(void)
{
    // TODO: update string output to include stat information
    std::string str{};
    std::stringstream ss(str);
    ss << m_name << ',';

    return ss.str();
}
