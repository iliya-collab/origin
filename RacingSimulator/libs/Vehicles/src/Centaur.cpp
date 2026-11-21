#include <string>
#include "Vehicles/Ground/Centaur.hpp"

Centaur::Centaur() : BaseGroundVehicle(AvailableVehicle::Centaur, 15.0, 8.0) {}

std::string Centaur::name() const
{
    return "Centaur";
}

std::string Centaur::info() const
{
    return name() + ": " + BaseGroundVehicle::info()
         + ", rest: 2h (always)";
}

double Centaur::restDurationFor(int /*index*/) const { return 2.0; }