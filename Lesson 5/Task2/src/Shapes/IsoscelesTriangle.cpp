#include "IsoscelesTriangle.h"
#include "InvalidShapeException.h"

IsoscelesTriangle::IsoscelesTriangle(double a, double b, double A, double B)
    : Triangle(a, b, a, A, B, A) 
{
    if (m_a != m_c)
		throw InvalidTriangleError("Sides a and c must be equal.");
	
	if (m_A != m_C)
		throw InvalidTriangleError("Angles a and c must be equal.");
} 