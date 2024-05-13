// ////////////////////////////////////////////////////////
//
// Author: Jared Lipkin
//
// Source file for Histogram class. Derived from Player,
// used to visualize graphs of data.
//
// ////////////////////////////////////////////////////////

#include "histogram.h"
#include "color.h"

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

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

void Histogram::display_histogram()
{
    std::cout << std::endl 
              << "  Player:         " << m_name << std::endl
              << "+------------------------------------------------------------------------------+" << std::endl
              << "| Games Won:      " << std::setw(4) << std::right << m_games_won << "/" << std::setw(5) << std::left << m_total_games;
    make_bar(m_games_won);
    std::cout << std::endl;
    for (int i = 1; i < 7; i++)
    {
        std::cout << "| Won in " << i;
        if (i == 1)
        {
            std::cout << " try:   ";
        }
        else
        {
            std::cout << " tries: ";
        }
        std::cout << std::setw(4) << std::right << m_game_data[i] << '/' << std::setw(5) << std::left << m_total_games;
        make_bar(m_game_data[i]);
        std::cout << std::endl;
    }
    std::cout << "+------------------------------------------------------------------------------+" << std::endl;
}

void Histogram::make_bar(int numerator)
{
    using namespace std;
    int percentage = 100 * numerator / m_total_games;
    string percent = to_string(percentage) + "%";
    while (percent.size() < 50)
    {
        percent.push_back(' ');
    }
    for (size_t i = 0; i < percent.size(); i++)
    {
        if (i < percentage/2)
        {
            cout << Color::setBg(Color::green) << percent[i] << Color::reset();
        }
        else
        {
            cout << Color::setBg(Color::black) << percent[i] << Color::reset();
        }
    }
    cout << " |";
}