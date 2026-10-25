#include "Square.h"
#include "InvalidShapeException.h"

Square::Square(double a)
    : Rectangle(a, a) 
{
    if ((m_a == m_b && m_a == m_c && m_b == m_c))
        throw InvalidQuadrilateralError("All sides must be equal.");
}