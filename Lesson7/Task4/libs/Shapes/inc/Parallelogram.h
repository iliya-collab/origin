#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H

#include "Quadrangle.h"

class SHAPE_API Parallelogram : public Quadrangle
{
public:
    Parallelogram(double a, double b, double A, double B);
};

#endif