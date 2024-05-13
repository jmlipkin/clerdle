#include "ansi_color.h"
#include <ostream>

std::ostream& operator<<(std::ostream& os, Color color) 
{
    os << "\e[" << static_cast<int>(color) << "m";
    return os;
}
