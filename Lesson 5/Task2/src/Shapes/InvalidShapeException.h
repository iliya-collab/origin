#ifndef INVALIDSHAPEEXCEPTION_H
#define INVALIDSHAPEEXCEPTION_H

#include <stdexcept>

class ShapeCreationError : public std::domain_error 
{
public:
    explicit ShapeCreationError(const std::string& message) 
        : std::domain_error(message) {}
};

class InvalidTriangleError : public ShapeCreationError {
public:
    InvalidTriangleError(const std::string& reason)
        : ShapeCreationError("Triangle creation failed: " + reason) {}
};

class InvalidQuadrilateralError : public ShapeCreationError {
public:
    explicit InvalidQuadrilateralError(const std::string& reason)
        : ShapeCreationError("Quadrilateral creation failed: " + reason) {}
};

#endif