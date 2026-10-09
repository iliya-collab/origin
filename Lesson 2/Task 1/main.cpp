#include <iostream>

class Shape 
{
protected:

    int m_sidesCount{};
    Shape(int sidesCount) : m_sidesCount{sidesCount} {}

public:

    Shape() = default;
    int getSidesCount() { return m_sidesCount; }

};

class Triangle : public Shape 
{
public:
    Triangle() : Shape(3) {}
};

class Quadrangle : public Shape
{
public:
    Quadrangle() : Shape(4) {}
};

int main() 
{
    std::cout << "Number of sides:" << std::endl;
    Shape s;
    std::cout << "Shape: " << s.getSidesCount() << std::endl;
    Triangle tr;
    std::cout << "Triangle: " << tr.getSidesCount() << std::endl;
    Quadrangle qu;
    std::cout << "Quadrangle: " << qu.getSidesCount() << std::endl;

    return EXIT_SUCCESS;
}