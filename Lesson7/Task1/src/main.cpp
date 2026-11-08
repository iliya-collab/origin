#include <iostream>
#include "Greeter.hpp"

int main()
{
    std::string name{};
    std::cout << "Your name: ";
    std::cin >> name;
    Greeter gr;
    gr.greet(name);
}