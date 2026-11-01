#include <iostream>
#include <string>
#include <cassert>
#include "Fraction.hpp"

int main()
{
    /*{
        Fraction f1(4, 3);
        Fraction f2(6, 11);
        std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << "\n";
        std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << "\n";
        std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << "\n";
        std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << "\n";
        std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << "\n";
        std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << "\n";
    }

    std::cout << "--------------------------------\n";

    {
        Fraction f1(4, 3);
        Fraction f2(8, 6);
        std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << "\n";
        std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << "\n";
    }

    std::cout << "--------------------------------\n";

    {
        int n1, d1;
        std::cout << "Input numerator first fraction: ";
        std::cin >> n1;
        std::cout << "Input denominator first fraction: ";
        std::cin >> d1;
        Fraction f1(n1, d1);
    

        int n2, d2;
        std::cout << "Input numerator second fraction: ";
        std::cin >> n2;
        std::cout << "Input denominator second fraction: ";
        std::cin >> d2;
        Fraction f2(n2, d2);

        std::cout << f1.dump() << " + " << f2.dump() << " = " << (f1 + f2).dump() << std::endl;
        std::cout << f1.dump() << " - " << f2.dump() << " = " << (f1 - f2).dump() << std::endl;
        std::cout << f1.dump() << " * " << f2.dump() << " = " << (f1 * f2).dump() << std::endl;
        std::cout << f1.dump() << " / " << f2.dump() << " = " << (f1 / f2).dump() << std::endl;

        Fraction f1_before_inc = f1;
        Fraction f3 = ++f1;
        Fraction multiply_res1 = f1 * f2; 

        std::cout << "++" << f1_before_inc.dump() << " * " << f2.dump() << " = " << multiply_res1.dump() << std::endl;
        std::cout << "The first fraction: " << f1.dump() << std::endl;

        Fraction f4 = f1--;
        Fraction multiply_res2 = f4 * f2; 

        std::cout << f4.dump() << "--" << " * " << f2.dump() << " = " << multiply_res2.dump() << std::endl;
        std::cout << "The first fraction: " << f1.dump() << std::endl;

    }*/

    // Тест 1: Проверка конструкторов и dump
    {
        Fraction f1(3, 4);
        Fraction f2(4, 5);
        assert(f1.dump() == "3/4");
        assert(f2.dump() == "4/5");
    }

    // Тест 2: Проверка неравенства    
    {        
        Fraction f1(4, 3);        
        Fraction f2(6, 11);        
        assert(!(f1 == f2));        
        assert(f1 != f2);        
        assert(!(f1 < f2));        
        assert(f1 > f2);        
        assert(!(f1 <= f2));        
        assert(f1 >= f2);   
    }    

    // Тест 3: Проверка равенства    
    {        
        Fraction f1(4, 3);        
        Fraction f2(8, 6);        
        assert(f1 == f2);        
        assert(!(f1 != f2));        
        assert(!(f1 < f2));        
        assert(!(f1 > f2));        
        assert(f1 <= f2);        
        assert(f1 >= f2);    
    }    

    // Тест 4: Проверка сценария    
    {        
        Fraction f1(3, 4);        
        Fraction f2(4, 5);        
        assert((f1 + f2).dump() == "31/20"); // 3/4 + 4/5 = 31/20        
        assert((f1 - f2).dump() == "-1/20"); // 3/4 - 4/5 = -1/20        
        assert((f1 * f2).dump() == "3/5");   // 3/4 * 4/5 = 3/5        
        assert((f1 / f2).dump() == "15/16"); // 3/4 / 4/5 = 15/16        
        assert((++f1 * f2).dump() == "7/5"); // ++3/4 * 4/5 = 7/5        
        assert(f1.dump() == "7/4");          // Значение дроби 1 = 7/4        
        assert((f1-- * f2).dump() == "7/5"); // 7/4-- * 4/5 = 7/5        
        assert(f1.dump() == "3/4");          // Значение дроби 1 = 3/4    
    }    

    // Тест 5: Дополнительные проверки с унарным минусом    
    {        
        Fraction f1(2, 3);       
        Fraction f2(-2, 3);        
        assert((-f1).dump() == "-2/3");        
        assert((-f2).dump() == "2/3");        
        assert((-f1) == f2);    
    }    

    // Тест 6: Проверка сокращения дробей    
    {        
        Fraction f1(4, 8);        
        Fraction f2(2, 4);        
        Fraction f3(1, 2);        
        assert(f1.dump() == "1/2");        
        assert(f2.dump() == "1/2");        
        assert(f3.dump() == "1/2");        
        assert(f1 == f2);        
        assert(f2 == f3);    
    }    

    // Тест 7: Проверка с отрицательными дробями    
    {        
        Fraction f1(-3, 4);        
        Fraction f2(3, -4);        
        Fraction f3(-3, -4);        
        assert(f1.dump() == "-3/4");        
        assert(f2.dump() == "-3/4");        
        assert(f3.dump() == "3/4");        
        assert(f1 == f2);        
        assert(f1 != f3);    
    }    

    std::cout << "All tests passed!" << std::endl;

    return EXIT_SUCCESS;
}