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

#include <iostream>

#include <string>
#include <sstream>

Player::Player(std::string name, std::vector<int> game_data)
{
    m_name = name;
    m_game_data = game_data;
    m_histogram = new Histogram(name, game_data);
}

Player::~Player()
{
    std::cout << "Player <" << get_name() << "> destructor" << std::endl;
    delete m_histogram;
    m_histogram = nullptr;
}

std::string Player::to_string(void)
{
    // TODO: Add quote/dequote functionality
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
