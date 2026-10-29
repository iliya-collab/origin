#include "Rhombus.h"
#include "InvalidShapeException.h"

Rhombus::Rhombus(double a, double A, double B)
	: Parallelogram(a, a, A, B)
{
	if (m_a != m_b || m_a != m_c || m_b != m_c)
        throw InvalidQuadrilateralError("All sides must be equal.");
}