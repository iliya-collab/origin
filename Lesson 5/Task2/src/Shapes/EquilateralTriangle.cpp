#include "EquilateralTriangle.h"
#include "InvalidShapeException.h"

EquilateralTriangle::EquilateralTriangle(double a) 
	: IsoscelesTriangle(a, a, 60, 60) 
{
	if (m_a != m_c || m_a != m_b || m_b != m_c)
		throw InvalidTriangleError("All sides must be equal.");
	
	if (m_A != 60 || m_B != 60 || m_C != 60)
		throw InvalidTriangleError("All angles must be equal 60.");
}