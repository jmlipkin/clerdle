#ifndef PUZZLE_H
#define PUZZLE_H

#include <vector>

class Puzzle {
    private:
        std::vector<char> m_solution;
    public:
        Puzzle();
        std::vector<char> get_solution() { return m_solution; }
        static bool is_valid_equation(const std::vector<char> &guess);
};

#endif