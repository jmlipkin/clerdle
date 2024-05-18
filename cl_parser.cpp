// ////////////////////////////////////////////////////////
//
// Author: Jared Lipkin
//
// Source file for CLParser class. Responsible for
// parsing user input to identify player name and any
// optional arguments.
//
// ////////////////////////////////////////////////////////

#include "cl_parser.h"
#include "game.h"
#include "player.h"

#include <vector>
#include <string>

#include <exception>
#include <stdexcept>

// temporary
#include <iostream>

const std::string CLParser::no_name = "NO NAME";

CLParser::CLParser(int count, char*args[])
{
    argc = count;
    int i{};
    while (i < count)
    {
        argv.push_back(args[i]);
        i++;
    }
    m_player_name = no_name;
    m_mode = Game::mode::usage;
    m_generator_count = 0;
}

void CLParser::parse_command_line()
{
    evaluate_bools();
    // will throw if argument combinations are invalid
    validate_bools();

    // runs appropriate setter function based on game mode
    if (g == true)
    {
        set_generator_count();
    }
    else {
        set_player_name();
    }

    if (h == true)
    {
        Game::display_usage();
    }
    set_game_mode();
}

void CLParser::evaluate_bools()
{
    for (auto i : argv)
    {
        if (i == "-s") {
            s = true;
        }
        if (i == "-t") {
            t = true;
        }
        if (i == "-g") {
            g = true;
        }
        if (i == "-h" || i == "--help") {
            h = true;
        }
    }
}

void CLParser::validate_bools()
{
    if ((g == true && s == true) ||
        (s == true && t == true) ||
        (g == true && t == true))
    {
        throw std::out_of_range("ERROR: Those arguments cannot be used together.");
    }
}

// interprets various flags, sets m_game_mode accordingly.
// Displays usage message if -h flag is thrown.
void CLParser::set_game_mode()
{
    if (s == true) {
        std::cout << "s is true" << std::endl;
        if (m_player_name != no_name)
        {
            m_mode = Game::playerstats;
        }
        else {
            m_mode = Game::allstats;
        }
    }
    else if (g == true) {   
        std::cout << "g is true" << std::endl; 
        m_mode = Game::generate;
    }
    else if (t == true) {
        std::cout << "t is true" << std::endl;
        m_mode = Game::test;
    }
    else if (m_player_name == no_name) {

        m_mode = Game::missing_player;
    }
    else {
        m_mode = Game::normal;
    }
}

// Checks to make sure only one player argument was found. If so, 
// stores that argument in m_player_name.
void CLParser::set_player_name()
{
    std::vector<std::string> name;
    // Checks every argument for a valid name. If found, stores in name vector.
    for (auto i : argv)
    {
        if (Player::is_valid_name(i))
        {
            name.push_back(i);
        }
    }
    // Checks to make sure only one valid name was found. If not, throws.
    if (name.size() == 1)
    {
        m_player_name = name[0];
    }
    else if (name.size() > 1)
    {
        throw std::invalid_argument("ERROR: Could not identify player name.");
    }
}

// Checks to make sure only one integer argument was found. If so, 
// stores that argument in m_generator_count.
void CLParser::set_generator_count()
{
    std::vector<int> candidate_nums;
    // Checks every argument for an integer. If found, stores in candidate_nums vector.
    for (auto i : argv)
    {
        if (std::all_of(i.begin(), i.end(), ::isdigit))
        {
            candidate_nums.push_back(stoi(i));
        } 
    }
    // Checks to make sure exactly one integer was found. If not, throws.
    if (candidate_nums.size() == 1)
    {
        m_generator_count = candidate_nums[0];
    }
    else
    {
        throw std::invalid_argument("ERROR: Could not identify generate mode specifier. Please enter one integer.");
    }
}