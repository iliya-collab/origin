#include <string>
#include "Vehicles/Air/FlyingCarpet.hpp"

FlyingCarpet::FlyingCarpet() : BaseAirVehicle(AvailableVehicle::FlyingCarpet, 10.0) {}

std::string FlyingCarpet::name() const
{
    return "Flying carpet";
}

std::string FlyingCarpet::info() const
{
    return name() + ": " + BaseVehicle::info()
         + ", reduction: 0% (<1000), 3% (<5000), 10% (<10000), 5% (>=10000)";
}

double FlyingCarpet::reductionFactorFor(double distance) const
{
    if (distance < 1000.0)  
        return 0.0;
    if (distance < 5000.0)  
        return 0.03;
    if (distance < 10000.0) 
        return 0.1;
    return 0.05;
}