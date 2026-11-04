#include <iostream>
#include "Triangle.h"

Triangle::Triangle(double a, double b, double c, 
            double A, double B, double C) 
    : m_a(a), m_b(b), m_c(c), m_A(A), m_B(B), m_C(C), IShape() {}

double Triangle::getSideA() const { return m_a; }
double Triangle::getSideB() const { return m_b; }
double Triangle::getSideC() const { return m_c; }
double Triangle::getAngleA() const { return m_A; }
double Triangle::getAngleB() const { return m_B; }
double Triangle::getAngleC() const { return m_C; }

void Triangle::printInfo() const 
{
    std::cout << "Sides: a=" << m_a << " , b=" << m_b << " , c=" << m_c << '\n'
                << "Angles: A=" << m_A << " , B=" << m_B << " , C=" << m_C << std::endl;
}