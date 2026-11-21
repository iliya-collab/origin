#ifndef VEHICLEEXCEPTION_HPP
#define VEHICLEEXCEPTION_HPP
#include <stdexcept>

class InvalidVehicleException : public std::logic_error
{
public:
    explicit InvalidVehicleException(const std::string& message) 
        : std::logic_error(message) {}
};

class FatalVehicleException : public std::runtime_error
{
public:
    explicit FatalVehicleException(const std::string& message) 
        : std::runtime_error(message) {}
};

// --------------------------------------------------------------------------------

class InvalidTypeVehicleException : public InvalidVehicleException
{
public:
    explicit InvalidTypeVehicleException(const std::string& message) 
        : InvalidVehicleException("Incorrect vehicle type: " + message) {}
};

class InvalidRegisteredVehicleException : public InvalidVehicleException
{
public:
    explicit InvalidRegisteredVehicleException(const std::string& message) 
        : InvalidVehicleException("Vehicle registration error: " + message) {}
};

class FatalRegisteredVehicleException : public FatalVehicleException
{
public:
    explicit FatalRegisteredVehicleException(const std::string& message) 
        : FatalVehicleException("Fatal registration error: " + message) {}
};

#endif