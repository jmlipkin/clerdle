// ////////////////////////////////////////////////////////
//
// Author: Jared Lipkin
//
// Header file for Histogram class. Derived from Player,
// used to visualize graphs of data.
//
// ////////////////////////////////////////////////////////

#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include <string>
#include <vector>

class Histogram {
    private:
        std::string m_name;
        std::vector<int> m_game_data;
        int m_total_games;
        int m_games_won;
    public:
        Histogram(std::string name, std::vector<int> game_data);
        void display_histogram(void);
};
#endif