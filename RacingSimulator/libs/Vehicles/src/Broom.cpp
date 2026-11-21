#include <string>
#include "Vehicles/Air/Broom.hpp"

Broom::Broom() : BaseAirVehicle(AvailableVehicle::Broom, 20.0) {}

std::string Broom::name() const
{
    return "Broom";
}

std::string Broom::info() const
{
    return name() + ": " + BaseVehicle::info()
         + ", reduction: +1% per 1000 distance";
}

double Broom::reductionFactorFor(double distance) const
{
    const int thousands = static_cast<int>(distance / 1000.0);
    return thousands * 0.01;
}