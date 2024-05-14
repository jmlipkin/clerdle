#ifndef GAME_H
#define GAME_H

#include "player_collection.h"

#include <string>
#include <vector>
class Game {
    public:
        typedef enum {
            usage,              // 0
            allstats,           // 1
            playerstats,        // 2
            test,               // 3
            generate,           // 4
            missing_player,     // 5
            play_with_help,     // 6
            normal              // 7
        } mode;
        static const std::vector<std::string> mode_map;

    private:
        PlayerCollection my_players;
        std::string m_player_name;
        mode m_mode;

        void normal_gameplay();
        void missing_player_mode();
        void generate_mode();

    public:
        Game(std::string player_name, mode mode) : m_player_name(player_name), m_mode(mode) {}
        void play();
        // TODO: add implementation
        static void display_usage();
};

#endif