#include <iostream>
#include "InvalidShapeException.h"
#include "Triangle.h"

Triangle::Triangle(double a, double b, double c, 
            double A, double B, double C) 
    : m_a(a), m_b(b), m_c(c), m_A(A), m_B(B), m_C(C), Shape(3) 
{
    if (m_sidesCount != 3)
        throw InvalidTriangleError("The number of sides in a triangle must be equal to 3.");

    if (a <= 0 || b <= 0 || c <= 0) 
        throw InvalidTriangleError("Sides must be greater than zero.");

    if (A <= 0 || B <= 0 || C <= 0) 
        throw InvalidTriangleError("All angles must be greater than zero.");

    if (a + b <= c || a + c <= b || b + c <= a) 
        throw InvalidTriangleError("One side is greater than or equal to the sum of the other two.");

    double sum_of_angles = A + B + C;
        
    if (std::abs(sum_of_angles - 180.0) > 0.001)
        throw InvalidTriangleError("The sum of angles must be exactly 180 degrees.");

}

double Triangle::getSideA() const { return m_a; }
double Triangle::getSideB() const { return m_b; }
double Triangle::getSideC() const { return m_c; }
double Triangle::getAngleA() const { return m_A; }
double Triangle::getAngleB() const { return m_B; }
double Triangle::getAngleC() const { return m_C; }

void Triangle::printInfo() const 
{
    Shape::printInfo();
    std::cout << "Sides: a=" << m_a << " , b=" << m_b << " , c=" << m_c << '\n'
                << "Angles: A=" << m_A << " , B=" << m_B << " , C=" << m_C << std::endl;
}