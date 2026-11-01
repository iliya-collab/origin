#ifndef FRACTIONEXCEPTION_HPP
#define FRACTIONEXCEPTION_HPP

#include <stdexcept>

class FractionException : public std::domain_error
{
public:
    explicit FractionException(const std::string& message) 
        : std::domain_error(message) {}
};

class DivisionByZeroException : public FractionException
{
public:
    explicit DivisionByZeroException(const std::string& message = "") 
        : FractionException("Division by zero") {}
};


#endif