#include <iostream>
#include "Quadrangle.h"

Quadrangle::Quadrangle(double a, double b, double c, double d, 
            double A, double B, double C, double D) 
    :   m_a(a), m_b(b), m_c(c), m_d(d),
         m_A(A), m_B(B), m_C(C), m_D(D), IShape() {}

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
    std::cout << "Sides: a=" << m_a << " , b=" << m_b << " , c=" << m_c << " , d=" << m_d << '\n'
                << "Angles: A=" << m_A << " , B=" << m_B << " , C=" << m_C << " , D=" << m_D << std::endl;
}