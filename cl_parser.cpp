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

void CLParser::parse_command_line()
{
    // TODO: fix exception throwing for too many names
    set_player_name();
}

