#ifndef RIGHTANGLEDTRIANGLE_H
#define RIGHTANGLEDTRIANGLE_H

#include "Triangle.h"

class SHAPE_API RightangledTriangle : public Triangle
{
public:
    RightangledTriangle(double a, double b, double c, double A, double B); 
};

#endif