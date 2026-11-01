#ifndef FRACTION_HPP
#define FRACTION_HPP

class Fraction 
{
private:

    int m_numerator;
    int m_denominator;

public:

    explicit Fraction(int n, int d);

    std::string dump() const;
    friend std::ostream& operator<<(std::ostream& os, const Fraction& frac);
    int GCD() const;
    bool simplify();

    explicit operator double() const;

    Fraction operator-() const;
    Fraction& operator++();
    Fraction operator++(int);
    Fraction& operator--();
    Fraction operator--(int);

    bool operator== (const Fraction& other) const;
    bool operator!= (const Fraction& other) const;
    bool operator< (const Fraction& other) const;
    bool operator> (const Fraction& other) const;
    bool operator<= (const Fraction& other) const;
    bool operator>= (const Fraction& other) const;

    Fraction operator+ (const Fraction& other) const;
    Fraction operator+ (double other) const;
    Fraction operator- (const Fraction& other) const;
    Fraction operator- (double other) const;
    Fraction operator* (const Fraction& other) const;
    Fraction operator/ (const Fraction& other) const;

};

#endif