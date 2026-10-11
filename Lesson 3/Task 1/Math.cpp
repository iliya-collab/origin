#include "Math.h"

double MyMath::add(double val1, double val2) { return val1 + val2; }

double MyMath::sub(double val1, double val2) { return val1 - val2; }

double MyMath::mul(double val1, double val2) { return val1 * val2; }

double MyMath::div(double val1, double val2) { return val1 / val2; }

double MyMath::pow(double base, int exp) 
{ 
    double res = 1;

    while (exp > 0)
    {
        if (exp % 2 == 1)
            res *= base;
        base *= base;
        exp /= 2;
    }
    
    return res;
}