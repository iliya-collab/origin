#include <iostream>
#include "Shapes/Shape.h"
#include "Shapes/Triangle.h"
#include "Shapes/IsoscelesTriangle.h"
#include "Shapes/EquilateralTriangle.h"
#include "Shapes/RightangledTriangle.h"
#include "Shapes/Quadrangle.h"
#include "Shapes/Parallelogram.h"
#include "Shapes/Rectangle.h"
#include "Shapes/Rhombus.h"
#include "Shapes/Square.h"
#include "Shapes/InvalidShapeException.h"

int main()
{
    try
    {
        std::cout << "Shape:" << std::endl;
        Shape* sh = new Shape();
        sh->printInfo();
        delete sh;
    }
    catch (const ShapeCreationError& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << "\nTriangle 1:" << std::endl;
        Triangle* sh = new Triangle(3, 4, 5, 30, 60, 90);
        sh->printInfo();
        delete sh;
    }
    catch (const ShapeCreationError& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << "\nTriangle 2:" << std::endl;
        Triangle* sh = new Triangle(3, 4, 5, 70, 60, 90);
        sh->printInfo();
        delete sh;
    }
    catch (const ShapeCreationError& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << "\nIsoscelesTriangle:" << std::endl;
        IsoscelesTriangle* sh = new IsoscelesTriangle(5, 6, 50, 80);
        sh->printInfo();
        delete sh;
    }
    catch (const ShapeCreationError& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << "\nEquilateralTriangle:" << std::endl;
        EquilateralTriangle* sh = new EquilateralTriangle(5);
        sh->printInfo();
        delete sh;
    }
    catch (const ShapeCreationError& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << "\nRightangledTriangle:" << std::endl;
        RightangledTriangle* sh = new RightangledTriangle(3, 4, 5, 30, 60);
        sh->printInfo();
        delete sh;
    }
    catch (const ShapeCreationError& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << "\nQuadrangle 1:" << std::endl;
        Quadrangle* sh = new Quadrangle(2, 3, 4, 5, 80, 100, 80, 100);
        sh->printInfo();
        delete sh;
    }
    catch (const ShapeCreationError& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << "\nQuadrangle 2:" << std::endl;
        Quadrangle* sh = new Quadrangle(3, 4, 5, 6, 120, 100, 90, 150);
        sh->printInfo();
        delete sh;
    }
    catch (const ShapeCreationError& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << "\nParallelogram:" << std::endl;
        Parallelogram* sh = new Parallelogram(4, 6, 60, 120);
        sh->printInfo();
        delete sh;
    }
    catch (const ShapeCreationError& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << "\nRectangle:" << std::endl;
        Rectangle* sh = new Rectangle(4, 6);
        sh->printInfo();
        delete sh;
    }
    catch (const ShapeCreationError& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << "\nRhombus:" << std::endl;
        Rhombus* sh = new Rhombus(5, 60, 120);
        sh->printInfo();
        delete sh;
    }
    catch (const ShapeCreationError& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << "\nSquare:" << std::endl;
        Square* sh = new Square(5);
        sh->printInfo();
        delete sh;
    }
    catch (const ShapeCreationError& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << "\nSquare:" << std::endl;
        Square* sh = new Square(-5);
        sh->printInfo();
        delete sh;
    }
    catch (const ShapeCreationError& e)
    {
        std::cerr << e.what() << '\n';
    }

    return EXIT_SUCCESS;
}