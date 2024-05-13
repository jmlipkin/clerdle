// ////////////////////////////////////////////////////////
//
// Author: Jared Lipkin
//
// Source file for PlayerCollection class. Responsible for
// reading and writing to CSV file and storing player data.
//
// ////////////////////////////////////////////////////////

#include "player_collection.h"
#include "player.h"

#include <vector>
#include <string>
#include <fstream>

const std::string PlayerCollection::filename = "player_data.csv";
const std::string PlayerCollection::file_header = "Player,None,A1,A2,A3,A4,A5,A6";

PlayerCollection::PlayerCollection()
{
    read_from_file();
}

PlayerCollection::~PlayerCollection()
{

}

void PlayerCollection::read_from_file(void)
{
    // TODO: extract strings of Players from CSV
    // and save as vector of Players
}

void PlayerCollection::write_to_file(void)
{
    // TODO: save vector of Players into CSV file
    using namespace std;
    ofstream out_file(filename);
    out_file << file_header << endl;
    for (Player* i : m_players)
    {
        out_file << i->to_string() << endl;
    }
}