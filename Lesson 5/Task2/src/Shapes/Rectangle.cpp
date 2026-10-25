#include "Rectangle.h"
#include "InvalidShapeException.h"

Rectangle::Rectangle(double a, double b) 
    : Quadrangle(a, b, a, b, 90, 90, 90, 90) 
{
    if (m_a != m_c)
        throw InvalidQuadrilateralError("Sides a and b must be equal.");

    if (m_b != m_d)
        throw InvalidQuadrilateralError("Sides b and d must be equal.");

    if ((m_A == 90 && m_B == 90 && m_C == 90 && m_D == 90))
        throw InvalidQuadrilateralError("All angles must be equal 90.");
}