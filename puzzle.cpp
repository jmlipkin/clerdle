#include "puzzle.h"
#include "color.h"

#include <iostream>
#include <random>
#include <string>

Puzzle::Puzzle()
{
    // TODO
    // temporary
    m_solution = "1*14-9=5";
}

bool Puzzle::is_valid_equation(const std::string &guess)
{
    if (guess.find_first_of('=') == std::string::npos)
        return false;
    if (guess.find('=') != guess.rfind('='))
        return false;
    if (guess.size() != 8)
        return false;
    if ()
}

void Puzzle::print_colored_char(const char&c, size_t i)
{
    using namespace std;
    if (c == '.')
    {
        cout << Color::setBg(Color::black) << Color::setFg(Color::green) << c << Color::reset();
        return;
    }
    if (is_correct_place(c, i))
    {
        cout << Color::setBg(Color::green) << Color::setFg(Color::black) << c << Color::reset();   
    }
    else if (is_wrong_spot(c, i))
    {
        cout << Color::setBg(Color::purple) << Color::setFg(Color::white) << c << Color::reset();
    }
    else {
        cout << Color::setBg(Color::black) << Color::setFg(Color::white) << c << Color::reset();
    }
}

bool Puzzle::is_correct_place(const char&c, size_t i)
{
    return c == m_solution[i];
}

bool Puzzle::is_wrong_spot(const char&c, size_t i)
{
    size_t found = m_solution.find(c);
    return found != std::string::npos && found != i;
}