#include <iostream>

class Shape 
{
protected:

    std::string m_name{"Shape"};
    int m_sidesCount{0};
    Shape(std::string_view name, int sidesCount) : m_name(name), m_sidesCount{sidesCount} {}

public:

    Shape() = default;
    virtual ~Shape() = default;

    std::string getName() const { return m_name; }
    int getSidesCount() const { return m_sidesCount; }

    virtual void printInfo() const
    {   
        std::cout << m_name << ":\n"
                    << (check() ? "Correct\n" : "Incorrect\n")
                    << "Number of sides: " << m_sidesCount << std::endl;
    }

    virtual bool check() const { return (m_sidesCount == 0); }

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

    Triangle(std::string_view name,
                double a, double b, double c, 
                double A, double B, double C) 
    : m_a(a), m_b(b), m_c(c), m_A(A), m_B(B), m_C(C), Shape(name, 3) {}

    double getSideA() const { return m_a; }
    double getSideB() const { return m_b; }
    double getSideC() const { return m_c; }
    double getAngleA() const { return m_A; }
    double getAngleB() const { return m_B; }
    double getAngleC() const { return m_C; }

    void printInfo() const override 
    {
        Shape::printInfo();
        std::cout << "Sides: a=" << m_a << " , b=" << m_b << " , c=" << m_c << '\n'
                    << "Angles: A=" << m_A << " , B=" << m_B << " , C=" << m_C << std::endl;
    }

    bool check() const override { return (m_sidesCount == 3) && ((m_A + m_B + m_C) == 180); }

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

    Quadrangle(std::string_view name,
                double a, double b, double c, 
                double d, double A, double B, 
                double C, double D) 
    :   m_a(a), m_b(b), m_c(c), m_d(d),
         m_A(A), m_B(B), m_C(C), m_D(D), Shape(name, 4) {}

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
        Shape::printInfo();
        std::cout << "Sides: a=" << m_a << " , b=" << m_b << " , c=" << m_c << " , d=" << m_d << '\n'
                    << "Angles: A=" << m_A << " , B=" << m_B << " , C=" << m_C << " , D=" << m_D << std::endl;
    }

    bool check() const override { return (m_sidesCount == 4) && ((m_A + m_B + m_C + m_D) == 360); }

};

// --------------------------------------------------------------------------------------------------------

class RightangledTriangle : public Triangle
{
public:
    RightangledTriangle(std::string_view name, double a, double b, double c, double A, double B) 
        : Triangle(name, a, b, c, A, B, 90) {}
    
    bool check() const override { return (m_C == 90) && Triangle::check(); }

};

class IsoscelesTriangle : public Triangle
{
public:
    IsoscelesTriangle(std::string_view name, double a, double b, double A, double B)
        : Triangle(name, a, b, a, A, B, A) {}

    bool check() const override { return (m_a == m_c) && (m_A == m_C) && Triangle::check(); }

};

class EquilateralTriangle : public IsoscelesTriangle
{
public:
    EquilateralTriangle(std::string_view name, double a) 
        : IsoscelesTriangle(name, a, a, 60, 60) {}

    bool check() const override { return (m_a == m_b) && (m_A == m_B) && (m_B == 60) && IsoscelesTriangle::check(); }

};

// --------------------------------------------------------------------------------------------------------

class Rectangle : public Quadrangle 
{
public: 
    Rectangle(std::string_view name, double a, double b) 
        : Quadrangle(name, a, b, a, b, 90, 90, 90, 90) {} 

    bool check() const override { 
        return (m_a == m_c) && (m_b == m_d) && 
                (m_A == 90) && (m_B == 90) && (m_C == 90) && (m_D == 90) && 
                Quadrangle::check(); 
    }

};

class Square : public Rectangle
{
public:
    Square(std::string_view name, double a)
        : Rectangle(name, a, a) {}

    bool check() const override { return (m_a == m_b) && Rectangle::check(); }

};

class Parallelogram : public Quadrangle
{
public:
    Parallelogram(std::string_view name, double a, double b, double A, double B)
        : Quadrangle(name, a, b, a, b, A, B, A, B) {}

    bool check() const override { 
        return (m_a == m_c) && (m_b == m_d) && 
                (m_A == m_C) && (m_B == m_D) && 
                Quadrangle::check(); 
    }

};

class Rhombus : public Parallelogram
{
public:
    Rhombus(std::string_view name, double a, double A, double B)
        : Parallelogram(name, a, a, A, B) {}

    bool check() const override { return (m_a == m_b) && Parallelogram::check(); }    

};

void printInfo(Shape* sh)
{
    sh->printInfo();
    std::cout << std::endl;
    delete sh;
}

int main() 
{
    printInfo(new Shape());

    printInfo(new Triangle("Triangle", 2, 3, 4, 30, 40, 50));

    printInfo(new RightangledTriangle("Right-angled triangle", 2, 3, 4, 30, 40));

    printInfo(new IsoscelesTriangle("Isosceles triangle", 2, 3, 30, 40));

    printInfo(new EquilateralTriangle("Equilateral triangle", 2));

    printInfo(new Quadrangle("Quadrilateral", 2, 3, 4, 5, 30, 40, 50, 60));

    printInfo(new Rectangle("Rectangle", 2, 3));

    printInfo(new Square("Square", 2));

    printInfo(new Parallelogram("Parallelogram", 2, 3, 30, 40));

    printInfo(new Rhombus("Rhombus", 2, 40, 80));

    return EXIT_SUCCESS;
}