#include <iostream>
#include "InvalidShapeException.h"
#include "Quadrangle.h"

Quadrangle::Quadrangle(double a, double b, double c, double d, 
            double A, double B, double C, double D) 
    :   m_a(a), m_b(b), m_c(c), m_d(d),
         m_A(A), m_B(B), m_C(C), m_D(D), Shape(4) 
{
    if (m_sidesCount != 4)
        throw InvalidTriangleError("The number of sides in a quadrangle must be equal to 4.");

    if (a <= 0 || b <= 0 || c <= 0 || d <= 0) 
        throw InvalidQuadrilateralError("All sides must be greater than zero.");

    if (A <= 0 || B <= 0 || C <= 0 || D <= 0) 
        throw InvalidQuadrilateralError("All angles must be greater than zero.");

    if (a >= b + c + d || b >= a + c + d || c >= a + b + d || d >= a + b + c) 
        throw InvalidQuadrilateralError("One side is greater than or equal to the sum of the other three.");

    double sum_of_angles = A + B + C + D;
    
    if (std::abs(sum_of_angles - 360.0) > 0.001) 
        throw InvalidQuadrilateralError("The sum of angles must be exactly 360 degrees.");
    
}

double Quadrangle::getSideA() const { return m_a; }
double Quadrangle::getSideB() const { return m_b; }
double Quadrangle::getSideC() const { return m_c; }
double Quadrangle::getSideD() const { return m_d; }
double Quadrangle::getAngleA() const { return m_A; }
double Quadrangle::getAngleB() const { return m_B; }
double Quadrangle::getAngleC() const { return m_C; }
double Quadrangle::getAngleD() const { return m_D; }

void Quadrangle::printInfo() const 
{
    Shape::printInfo();
    std::cout << "Sides: a=" << m_a << " , b=" << m_b << " , c=" << m_c << " , d=" << m_d << '\n'
                << "Angles: A=" << m_A << " , B=" << m_B << " , C=" << m_C << " , D=" << m_D << std::endl;
}