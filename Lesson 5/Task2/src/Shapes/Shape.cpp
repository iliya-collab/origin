#include "Shape.h"
#include <iostream>

void Shape::printInfo() const
{   
    std::cout << "Number of sides: " << m_sidesCount << std::endl;
}