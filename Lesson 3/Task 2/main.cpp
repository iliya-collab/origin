#include <iostream>
#include "Counter.h"

int main() {

    std::cout << "Do you want to specify the initial counter value? Enter yes/no: ";
    std::string cmd;
    std::cin >> cmd;

    Counter counter;

    if (cmd == "yes")
    {
        std::cout << "Enter the initial counter value: ";
        int val;
        std::cin >> val;
        counter = Counter(val);
    }
    else
        counter = Counter();

    cmd = "";
    while (cmd != "x")
    {
        std::cout << "Enter a command ('+', '-', '=' or 'x'): ";
        std::cin >> cmd;

        if (cmd == "+")
            counter.inc();
        else if (cmd == "-")
            counter.dec();
        else if (cmd == "=")
            std::cout << counter.current() << std::endl;
    }
    
    return EXIT_SUCCESS;
}