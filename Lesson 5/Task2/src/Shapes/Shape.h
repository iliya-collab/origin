#ifndef SHAPE_H
#define SHAPE_H
#include <string>

class Shape 
{
protected:

    int m_sidesCount{0};
    Shape(int sidesCount) : m_sidesCount{sidesCount} {}

public:

    Shape() = default;
    virtual ~Shape() = default;

    int getSidesCount() const { return m_sidesCount; }

    virtual void printInfo() const;

};


#endif