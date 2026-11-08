#include <string>
#include <iostream>
#include "../inc/Greeter.hpp"

void Greeter::greet(std::string_view name)
{
    std::cout << "Hello, " << name << "!\n";
}