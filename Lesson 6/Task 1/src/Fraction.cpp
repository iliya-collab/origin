#include <string>
#include "Fraction.hpp"
#include "FractionException.hpp"

std::ostream& operator<<(std::ostream& os, const Fraction& frac)
{
    os << frac.dump();
    return os;
}

Fraction::Fraction(int n, int d) 
    : m_numerator(n), m_denominator(d) 
{
    if (d == 0)
        throw DivisionByZeroException();

    bool isNegative = (m_numerator < 0) ^ (m_denominator < 0); 

    m_numerator = isNegative ? -std::abs(m_numerator) : std::abs(m_numerator);
    m_denominator = std::abs(m_denominator);

    simplify();
}

std::string Fraction::dump() const
{
    return std::to_string(m_numerator) + "/" + std::to_string(m_denominator);
}

int Fraction::GCD() const
{
    int A = std::abs(m_numerator);
    int B = std::abs(m_denominator);

    if (A == 0 && B == 0)
        return 0;

    while (B != 0)
    {
        int R = A % B;
        A = B;
        B = R;
    }

    return A;
}

bool Fraction::simplify() 
{
    int gcd = GCD();

    if (gcd <= 1)
        return false;

    m_numerator /= gcd;
    m_denominator /= gcd;

    return true;
}

Fraction Fraction::operator-() const
{
    return Fraction(-m_numerator, std::abs(m_denominator));
}

Fraction& Fraction::operator++()
{
    *this = *this + 1;
    return *this;
}

Fraction Fraction::operator++(int)
{
    Fraction temp = *this; 
    *this = *this + 1;
    return temp;
}

Fraction& Fraction::operator--()
{
    *this = *this - 1;
    return *this;
}

Fraction Fraction::operator--(int)
{
    Fraction temp = *this; 
    *this = *this - 1;
    return temp;
}

Fraction::operator double() const
{
    if (m_denominator == 0)
        throw DivisionByZeroException();
    return m_numerator / m_denominator;
}
bool Fraction::operator== (const Fraction& other) const
{
    return (m_numerator == other.m_numerator) && 
            (m_denominator == other.m_denominator);
}

bool Fraction::operator!= (const Fraction& other) const
{
    return !(*this == other);
}

bool Fraction::operator< (const Fraction& other) const
{
    return this->m_numerator * other.m_denominator < this->m_denominator * other.m_numerator;
}

bool Fraction::operator> (const Fraction& other) const
{
    return this->m_numerator * other.m_denominator > this->m_denominator * other.m_numerator;
}

bool Fraction::operator<= (const Fraction& other) const
{
    return this->m_numerator * other.m_denominator <= this->m_denominator * other.m_numerator;
}

bool Fraction::operator>= (const Fraction& other) const
{
    return this->m_numerator * other.m_denominator >= this->m_denominator * other.m_numerator;
}

Fraction Fraction::operator+ (const Fraction& other) const
{
    Fraction newFrac(this->m_numerator * other.m_denominator + this->m_denominator * other.m_numerator,
                    this->m_denominator * other.m_denominator);
    return newFrac;
}

Fraction Fraction::operator+ (double other) const
{
    Fraction newFrac(this->m_numerator + other * this->m_denominator,
                     this->m_denominator);
    return newFrac;
}

Fraction Fraction::operator- (const Fraction& other) const
{
    Fraction newFrac(this->m_numerator * other.m_denominator - this->m_denominator * other.m_numerator,
                    this->m_denominator * other.m_denominator);
    return newFrac;
}

Fraction Fraction::operator- (double other) const
{
    Fraction newFrac(this->m_numerator - other * this->m_denominator,
                     this->m_denominator);
    return newFrac;
}

Fraction Fraction::operator* (const Fraction& other) const
{
    return Fraction(this->m_numerator * other.m_numerator, 
                    this->m_denominator * other.m_denominator);
}

Fraction Fraction::operator/ (const Fraction& other) const
{
    return Fraction(this->m_numerator * other.m_denominator, 
                    this->m_denominator * other.m_numerator);
}