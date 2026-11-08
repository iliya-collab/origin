#include <iostream>
#include <string>
#include "../inc/Leaver.hpp"

void Leaver::leaver(std::string_view name)
{
    std::cout << "Goodbye, " << name << "!\n";
}