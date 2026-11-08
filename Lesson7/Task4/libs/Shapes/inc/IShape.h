#ifndef SHAPE_H
#define SHAPE_H
#include "ShapeApi.h"

class SHAPE_API IShape 
{
public:

    IShape() = default;
    virtual ~IShape() = default;

    virtual void printInfo() const = 0;

};

void SHAPE_API printInfo(IShape* sh);

#endif