#include <string>
#include "Vehicles/Air/Eagle.hpp"

Eagle::Eagle() : BaseAirVehicle(AvailableVehicle::Eagle, 8.0) {}

std::string Eagle::name() const
{
    return "Eagle";
}

std::string Eagle::info() const
{
    return name() + ": " + BaseVehicle::info()
         + ", reduction: 6% (always)";
}

double Eagle::reductionFactorFor(double /*distance*/) const
{
    return 0.06;
}