#ifndef PUZZLE_H
#define PUZZLE_H

#include <string>

class Puzzle {
    private:
        std::string m_solution;
    public:
        Puzzle();
        std::string get_solution() { return m_solution; }
        static bool is_valid_equation(const std::string &guess);
        void print_colored_char(const char &c, size_t i);
        bool is_correct_place(const char &c, size_t i);
        bool is_wrong_spot(const char &c, size_t i);
};

#endif