#include "Parallelogram.h"
#include "InvalidShapeException.h"

Parallelogram::Parallelogram(double a, double b, double A, double B)
	: Quadrangle(a, b, a, b, A, B, A, B) 
{
	if (m_a != m_c)
        throw InvalidQuadrilateralError("Sides a and b must be equal.");

    if (m_b != m_d)
        throw InvalidQuadrilateralError("Sides b and d must be equal.");

    if (m_A != m_C)
        throw InvalidQuadrilateralError("Angles A and C must be equal.");

	if (m_B != m_D)
        throw InvalidQuadrilateralError("Angles B and D must be equal.");
}