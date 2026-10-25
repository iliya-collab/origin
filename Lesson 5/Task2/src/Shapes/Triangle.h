#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Shape.h"

class Triangle : public Shape 
{
protected:

    double m_a{};
    double m_b{};
    double m_c{};
    double m_A{};
    double m_B{};
    double m_C{};

public:

    Triangle(double a, double b, double c, 
            double A, double B, double C);

    double getSideA() const;
    double getSideB() const;
    double getSideC() const;
    double getAngleA() const;
    double getAngleB() const;
    double getAngleC() const;

    void printInfo() const override;
};

#endif