// ////////////////////////////////////////////////////////
//
// Author: Jared Lipkin
//
// Simple file to print various color options based on
// ansi_color.
//
// ////////////////////////////////////////////////////////

#include "color.h"
#include <iostream>

int main(void)
{
    using namespace std;
    Color::test();
    cout << "Testing normal." /*<< Color::setFg(Color::green)*/ << Color::setBg(Color::red) << "other text   |" << Color::reset() << endl;
    return 0;
}