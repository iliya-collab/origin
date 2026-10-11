#include <iostream>
#include "Math.h"

int main()
{
    double val1, val2;
    char cop;

    std::cout << "Enter first value: ";
    std::cin >> val1;

    std::cout << "Enter second value: ";
    std::cin >> val2;

    std::cout << "Select operation (1 - add, 2 - sub, 3 - mul, 4 - div, 5 - pow): ";
    std::cin >> cop;

    switch (cop)
    {
    case '1':
        std::cout << val1 << " + " << val2 << " = " << MyMath::add(val1, val2) << std::endl;
        break;
    case '2':
        std::cout << val1 << " - " << val2 << " = " << MyMath::sub(val1, val2) << std::endl;
        break;
    case '3':
        std::cout << val1 << " * " << val2 << " = " << MyMath::mul(val1, val2) << std::endl;
        break;
    case '4':
        std::cout << val1 << " / " << val2 << " = " << MyMath::mul(val1, val2) << std::endl;
        break;
    case '5':
        std::cout << val1 << " ^ " << val2 << " = " << MyMath::pow(val1, val2) << std::endl;
        break;
    default:
        std::cout << "Unknown operation" << std::endl;
        break;
    }

    return EXIT_SUCCESS;
}