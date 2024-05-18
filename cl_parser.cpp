// ////////////////////////////////////////////////////////
//
// Author: Jared Lipkin
//
// Header file for CLParser class. Responsible for
// parsing user input to identify player name and any
// optional arguments.
//
// ////////////////////////////////////////////////////////

#include "cl_parser.h"
#include "game.h"

#include <iostream>
#include <vector>
#include <string>
#include <exception>
#include <stdexcept>

CLParser::CLParser(int count, char* args[])
{
    argc = count;
    int i = 0;
    while (i < count)
    {
        argv.push_back(args[i]);
        i++;
    }
}

void CLParser::set_player_name(void)
{
    std::vector<std::string> name;
    int i{};
    while (i < argc)
    {
        std::string nameContender = argv[i];
        std::string args_prefix = "-";
        std::string exe_prefix = ".";

        if (nameContender.rfind(args_prefix, 0) != 0 && nameContender.rfind(exe_prefix, 0) != 0)
        {
            name.push_back(nameContender);
        }
        i++;
    }
    if (name.size() > 1)
    {
        throw std::invalid_argument("ERROR: Could not identify player name.");
    }
    else if (name.size() ==1)
    {
        m_player_name = name[0];
    }
}

std::string CLParser::get_player_name()
{
    return m_player_name;
}

Game::mode CLParser::parse_command_line()
{
    set_player_name();

    bool h, s, t, g = false;
    evaluate_bools(h, s, t, g);

    if (h == true)
    {
        Game::display_usage();
    }
    if ((g == true && s == true) || (s == true && t == true) || (g == true && t == true))
    {
        throw std::out_of_range("ERROR: Those arguments cannot be used together.");
    }
    if (g == true)
    {
        set_generator_count();
        return Game::mode::generate;
    }
    if (s == true)
    {
        if (m_player_name != "NO NAME")
            return Game::mode::playerstats;
        else if (s == true)
            return Game::mode::allstats;
    }
    if (t == true)
    {
        return Game::mode::test;
    }
    
    if (m_player_name == "NO NAME")
    {
        return Game::mode::missing_player;
    }
    return Game::mode::normal;
}

void CLParser::evaluate_bools(bool &h, bool &s, bool &t, bool &g)
{
    for (auto i : argv)
    {
        if (i == "-s")
            s = true;
        if (i == "-t")
            t = true;
        if (i == "-g")
            g = true;
        if (i == "-h" || i == "--help")
            h = true;
    }
}

void CLParser::set_generator_count()
{
    std::vector<int> candidate_nums;
    int cand = 0;
    for (auto i : argv)
    {
        try 
        {
            cand = stoi(i);
            candidate_nums.push_back(cand);
            std::cout << '<' << i << "> added to int vector." << std::endl;
        }
        catch (...)
        {
            std::cout << '<' << i << "> not added to int vector." << std::endl;
            continue;
        }
    }

}

int CLParser::get_generator_count()
{
    return m_gen_count;
}