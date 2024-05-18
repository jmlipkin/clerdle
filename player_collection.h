// ////////////////////////////////////////////////////////
//
// Author: Jared Lipkin
//
// Header file for PlayerCollection class. Responsible for
// reading and writing to CSV file and storing player data.
//
// ////////////////////////////////////////////////////////

#ifndef PLAYER_COLLECTION_H
#define PLAYER_COLLECTION_H

#include "player.h"
#include <vector>
#include <string>

class PlayerCollection {
    private:
        std::vector <Player*> m_players;
        static const std::string filename;
        static const std::string file_header;

        // File I/O
        void read_from_file(void);
        void write_to_file(void);
        void dequote(std::string &string);

        void add_player_from_in_vector(std::vector<std::string>&);

    public:
        PlayerCollection();
        ~PlayerCollection();

        void update_player_data(const std::string &name, const int &trial);

        void display_all_stats();
        void display_player_stats(const std::string &name);
};

#endif