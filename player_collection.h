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

        // File I/o
        void read_from_file(void);
        void write_to_file(void);

    public:
        PlayerCollection();
        ~PlayerCollection();
};

#endif