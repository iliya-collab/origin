#ifndef QUADRANGLE_H
#define QUADRANGLE_H
#include "Shape.h"

class Quadrangle : public Shape
{
protected:

    double m_a{};
    double m_b{};
    double m_c{};
    double m_d{};
    double m_A{};
    double m_B{};
    double m_C{};
    double m_D{};

public:

    Quadrangle(double a, double b, double c, double d, 
            double A, double B, double C, double D);

    double getSideA() const;
    double getSideB() const;
    double getSideC() const;
    double getSideD() const;
    double getAngleA() const;
    double getAngleB() const;
    double getAngleC() const;
    double getAngleD() const;

    void printInfo() const override;

};

#endif