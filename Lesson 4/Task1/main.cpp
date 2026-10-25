#define MODE 10

#ifndef MODE
#error The need to define MODE
#endif

#if MODE == 1
    inline double add(double a, double b) { return a + b; }
#endif

#include <iostream>

int main()
{
#if MODE == 0
    std::cout << "I am working in training mode" << std::endl;
#elif MODE == 1
    std::cout << "I am working in combat mode" << std::endl;
    double a, b;
    std::cout << "a = ";
    std::cin >> a;
    std::cout << "b = ";
    std::cin >> b;
    std::cout << "a + b = " << add(a, b) << std::endl;
#else
    std::cout << "Unknown mode. Shutting down" << std::endl;
    return EXIT_FAILURE;
#endif

    return EXIT_SUCCESS;
}