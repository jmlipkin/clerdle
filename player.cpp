// ////////////////////////////////////////////////////////
//
// Author: Jared Lipkin
//
// Source file for PlayerStats class. Responsible for
// manipulating individual player data.
//
// ////////////////////////////////////////////////////////

#include "player.h"
#include "histogram.h"

#include <string>
#include <sstream>

const std::string Player::no_name = "NO NAME";

Player::Player(std::string name, std::vector<int> game_data)
{
    m_name = name;
    m_game_data = game_data;
    m_histogram = new Histogram(name, game_data);
}

Player::~Player()
{
    delete m_histogram;
    m_histogram = nullptr;
}

std::string Player::to_string(void)
{
    std::string str{};
    std::stringstream ss(str);
    ss << m_name << ',';
    for (auto i : m_game_data)
    {
        ss << i << ',';
    }
    str = ss.str();
    str.pop_back();
    return str;
}

std::string Player::to_quoted_string(void)
{
    std::string str{};
    std::stringstream ss(str);
    ss << '\"' << m_name << "\",";
    for (auto i : m_game_data)
    {
        ss << i << ',';
    }
    str = ss.str();
    str.pop_back();
    return str;
}

bool Player::is_valid_name(const std::string &name)
{
    char args_prefix = '-';
    char exe_prefix = '.';

    if (name.rfind(args_prefix, 0) == 0 || name.rfind(exe_prefix, 0) == 0)
    {
        return false;
    }

    if (name.find("\"") != std::string::npos || name.find(',') != std::string::npos)
    {
        return false;
    }

    return true;
}