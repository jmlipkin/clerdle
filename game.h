#ifndef GAME_H
#define GAME_H

#include "player_collection.h"
#include "player.h"
#include "puzzle.h"

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
        // Game settings
        PlayerCollection my_players{};
        Puzzle* m_solution;
        std::string m_player_name;
        mode m_mode;
        int m_generator_count;

        // Board data
        std::vector<std::string> m_board;
        std::string m_keyboard;

        // constant game variables
        const int max_tries{6};
        const int game_over{0};

        static const std::string board_init;
        static const std::string keyboard_init;

        // gameplay functions
        void normal_game();
        void prompt_for_name();
        std::string prompt_for_guess();
        bool is_solution(const std::string &guess);

        // setup functions
        void initialize_board();
        // void initialize_keyboard();

        // board functions
        void draw_board();
        void draw_keyboard();
        void update_board(const std::string &guess, const int trial);
        void update_keyboard(const std::string &guess);


    public:
        Game(std::string player_name, mode mode, int gen_count);
        ~Game();

        void play();
        static void display_usage();

        // Getter functions -- temporary
        std::string get_player_name() { return m_player_name; }
        mode get_mode() { return m_mode; }
        int get_generator_count() { return m_generator_count; }
};

#endif