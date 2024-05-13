#ifndef GAME_H
#define GAME_H

class Game {
    public:
        typedef enum {
            usage,
            allstats,
            playerstats,
            test,
            generate,
            missing_player,
            play_with_help,
            normal
        } mode;
        // TODO: add implementation
        static void display_usage() {}
};

#endif