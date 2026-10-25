#include <iostream>
#include "Shapes/Triangle.h"
#include "Shapes/Quadrangle.h"
#include "Shapes/InvalidShapeException.h"

int main() 
{
    try
    {
        std::cout << "Triangle 1:" << std::endl;
        Triangle* sh1 = new Triangle(3, 4, 5, 30, 60, 90);
        sh1->printInfo();
        delete sh1;
    }
    catch(const ShapeCreationError& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << "Triangle 2:" << std::endl;
        Triangle* sh2 = new Triangle(3, 4, 5, 70, 60, 90);
        sh2->printInfo();
        delete sh2;
    }
    catch(const ShapeCreationError& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << "Quadrangle 1:" << std::endl;
        Quadrangle* sh3 = new Quadrangle(3, 4, 5, 6, 60, 60, 90, 150);
        sh3->printInfo();
        delete sh3;
    }
    catch(const ShapeCreationError& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << "Quadrangle 2:" << std::endl;
        Quadrangle* sh4 = new Quadrangle(3, 4, 5, 6, 120, 100, 90, 150);
        sh4->printInfo();
        delete sh4;
    }
    catch(const ShapeCreationError& e)
    {
        std::cerr << e.what() << '\n';
    }

    return EXIT_SUCCESS;
}