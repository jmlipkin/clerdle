// ////////////////////////////////////////////////////////
//
// Author: Jared Lipkin
//
// Source file for Histogram class. Derived from Player,
// used to visualize graphs of data.
//
// ////////////////////////////////////////////////////////

#include "histogram.h"

#include <string>
#include <vector>

Histogram::Histogram(std::string name, std::vector<int> game_data)
{
    m_name = name;
    m_game_data = game_data;

    for (int i : game_data)
    {
        m_total_games += i;
    }
    m_games_won = m_total_games - game_data[0];
}