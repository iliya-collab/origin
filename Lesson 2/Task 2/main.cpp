#include <iostream>

class Shape 
{
public:

    Shape() = default;
    virtual ~Shape() = default;

    virtual void printInfo() const = 0;

};

// -------------------------------------------------------------------------------------------------------

class Triangle : public Shape 
{
protected:

    double m_a{};
    double m_b{};
    double m_c{};
    double m_A{};
    double m_B{};
    double m_C{};

public:

    Triangle(double a, double b, double c, 
            double A, double B, double C) 
    : m_a(a), m_b(b), m_c(c), m_A(A), m_B(B), m_C(C), Shape() {}

    double getSideA() const { return m_a; }
    double getSideB() const { return m_b; }
    double getSideC() const { return m_c; }
    double getAngleA() const { return m_A; }
    double getAngleB() const { return m_B; }
    double getAngleC() const { return m_C; }

    void printInfo() const override 
    {
        std::cout << "Sides: a=" << m_a << " , b=" << m_b << " , c=" << m_c << '\n'
                    << "Angles: A=" << m_A << " , B=" << m_B << " , C=" << m_C << std::endl;
    }
};

class Quadrangle : public Shape
{
protected:

    double m_a{};
    double m_b{};
    double m_c{};
    double m_d{};
    double m_A{};
    double m_B{};
    double m_C{};
    double m_D{};

public:

    Quadrangle(double a, double b, double c, double d, 
            double A, double B, double C, double D) 
    :   m_a(a), m_b(b), m_c(c), m_d(d),
         m_A(A), m_B(B), m_C(C), m_D(D), Shape() {}

    double getSideA() const { return m_a; }
    double getSideB() const { return m_b; }
    double getSideC() const { return m_c; }
    double getSideD() const { return m_d; }
    double getAngleA() const { return m_A; }
    double getAngleB() const { return m_B; }
    double getAngleC() const { return m_C; }
    double getAngleD() const { return m_D; }

    void printInfo() const override 
    {
        std::cout << "Sides: a=" << m_a << " , b=" << m_b << " , c=" << m_c << " , d=" << m_d << '\n'
                    << "Angles: A=" << m_A << " , B=" << m_B << " , C=" << m_C << " , D=" << m_D << std::endl;
    }

};

// --------------------------------------------------------------------------------------------------------

class RightangledTriangle : public Triangle
{
public:
    RightangledTriangle(double a, double b, double c, double A, double B) 
        : Triangle(a, b, c, A, B, 90) {}
};

class IsoscelesTriangle : public Triangle
{
public:
    IsoscelesTriangle(double a, double b, double A, double B)
        : Triangle(a, b, a, A, B, A) {}
};

class EquilateralTriangle : public IsoscelesTriangle
{
public:
    EquilateralTriangle(double a) 
        : IsoscelesTriangle(a, a, 60, 60) {}
};

// --------------------------------------------------------------------------------------------------------

class Rectangle : public Quadrangle 
{
public: 
    Rectangle(double a, double b) 
        : Quadrangle(a, b, a, b, 90, 90, 90, 90) {} 
};

class Square : public Rectangle
{
public:
    Square(double a)
        : Rectangle(a, a) {}
};

class Parallelogram : public Quadrangle
{
public:
    Parallelogram(double a, double b, double A, double B)
        : Quadrangle(a, b, a, b, A, B, A, B) {}
};

class Rhombus : public Parallelogram
{
public:
    Rhombus(double a, double A, double B)
        : Parallelogram(a, a, A, B) {}
};

void printInfo(Shape* sh)
{
    sh->printInfo();
    delete sh;
}

int main() 
{
    std::cout << "Triangle:" << std::endl;
    printInfo(new Triangle(2, 3, 4, 30, 40, 50));

    std::cout << "Right-angled triangle:" << std::endl;
    printInfo(new RightangledTriangle(2, 3, 4, 30, 40));

    std::cout << "Isosceles triangle:" << std::endl;
    printInfo(new IsoscelesTriangle(2, 3, 30, 40));

    std::cout << "Equilateral triangle:" << std::endl;
    printInfo(new EquilateralTriangle(2));

    std::cout << "Quadrilateral:" << std::endl;
    printInfo(new Quadrangle(2, 3, 4, 5, 30, 40, 50, 60));

    std::cout << "Rectangle:" << std::endl;
    printInfo(new Rectangle(2, 3));

    std::cout << "Square:" << std::endl;
    printInfo(new Square(2));

    std::cout << "Parallelogram:" << std::endl;
    printInfo(new Parallelogram(2, 3, 30, 40));

    std::cout << "Rhombus:" << std::endl;
    printInfo(new Rhombus(2, 40, 80));

    return EXIT_SUCCESS;
}