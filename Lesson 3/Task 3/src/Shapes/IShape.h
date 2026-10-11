#ifndef SHAPE_H
#define SHAPE_H

class IShape 
{
public:

    IShape() = default;
    virtual ~IShape() = default;

    virtual void printInfo() const = 0;

};

void printInfo(IShape* sh);

#endif