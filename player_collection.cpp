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
#include <sstream>

const std::string PlayerCollection::filename = "player_data.csv";
const std::string PlayerCollection::file_header = "Player,None,A1,A2,A3,A4,A5,A6";

PlayerCollection::PlayerCollection()
{
    read_from_file();
}

PlayerCollection::~PlayerCollection()
{
    write_to_file();
    for (auto i : m_players)
    {
        delete i;
        i = nullptr;
    }
    m_players.clear();
}

void PlayerCollection::read_from_file(void)
{
    using namespace std;
    ifstream in_file(filename);
    string line;
    int i = 0;
    while (getline(in_file, line))
    {
        i++;
        // Skip header line
        if (i == 1)
        {
            continue;
        }
        vector<string> row;
        istringstream ss(line);
        string holder{};
        while (getline(ss, holder, ','))
        {
            row.push_back(holder);
        }
        add_player_from_in_vector(row);
    }
    in_file.close();
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
    out_file.close();
}

void PlayerCollection::add_player_from_in_vector(std::vector<std::string> &row)
{
    std::string player_name = row[0];
    std::vector<int> game_data;
    row.erase(row.begin());
    for (std::string i : row)
    {
        game_data.push_back(stoi(i));
    }
    Player *playerptr = new Player(player_name, game_data);
    m_players.push_back(playerptr);
}