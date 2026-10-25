#include "RightangledTriangle.h"
#include "InvalidShapeException.h"

RightangledTriangle::RightangledTriangle(double a, double b, double c, double A, double B) 
    : Triangle(a, b, c, A, B, 90) 
{
    if (m_C != 90)
		throw InvalidTriangleError("Angle C must be 90.");
}