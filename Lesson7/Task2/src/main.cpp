#include <iostream>
#include "Leaver.hpp"

int main()
{
    std::string name{};
    std::cout << "Your name: ";
    std::cin >> name;
    Leaver lv;
    lv.leaver(name);
}