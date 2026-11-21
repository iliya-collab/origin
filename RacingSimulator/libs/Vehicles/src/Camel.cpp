#include <string>
#include "Vehicles/Ground/Camel.hpp"

Camel::Camel() : BaseGroundVehicle(AvailableVehicle::Camel, 10.0, 30.0) {};

std::string Camel::name() const
{
    return "Camel";
}

std::string Camel::info() const
{
    return name() + ": " + BaseGroundVehicle::info()
         + ", rest: 5h (first), 8h (subsequent)";
}

double Camel::restDurationFor(int index) const
{
    return index == 0 ? 5.0 : 8.0;
}