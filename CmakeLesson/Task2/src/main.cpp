#include <iostream>
#include "Shapes/Triangle.h"
#include "Shapes/RightangledTriangle.h"
#include "Shapes/IsoscelesTriangle.h"
#include "Shapes/EquilateralTriangle.h"
#include "Shapes/Quadrangle.h"
#include "Shapes/Rectangle.h"
#include "Shapes/Rectangle.h"
#include "Shapes/Square.h"
#include "Shapes/Parallelogram.h"
#include "Shapes/Rhombus.h"

int main() 
{
    std::cout << "Triangle:" << std::endl;
    printInfo(new Triangle(2, 3, 4, 30, 40, 50));

    std::cout << "Right-angled triangle:" << std::endl;
    printInfo(new RightangledTriangle(2, 3, 4, 30, 40));

    std::cout << "Isosceles triangle:" << std::endl;
    printInfo(new IsoscelesTriangle(2, 3, 30, 40));

    std::cout << "Equilateral triangle:" << std::endl;
    printInfo(new EquilateralTriangle(2));

    std::cout << "Quadrilateral:" << std::endl;
    printInfo(new Quadrangle(2, 3, 4, 5, 30, 40, 50, 60));

    std::cout << "Rectangle:" << std::endl;
    printInfo(new Rectangle(2, 3));

    std::cout << "Square:" << std::endl;
    printInfo(new Square(2));

    std::cout << "Parallelogram:" << std::endl;
    printInfo(new Parallelogram(2, 3, 30, 40));

    std::cout << "Rhombus:" << std::endl;
    printInfo(new Rhombus(2, 40, 80));

    return EXIT_SUCCESS;
}