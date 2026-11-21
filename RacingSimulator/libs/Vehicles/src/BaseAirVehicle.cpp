#include <cmath>
#include "BaseAirVehicle.hpp"

BaseAirVehicle::BaseAirVehicle(AvailableVehicle vehicle, double velocity)
    : BaseVehicle(TypeVehicle::Air, vehicle, velocity) {};

double BaseAirVehicle::run(double distanceToFinish)
{
    if (m_velocity <= 0.0) 
        return std::numeric_limits<double>::infinity();
    if (distanceToFinish <= 0.0)   
        return 0.0;

    const double factor = reductionFactorFor(distanceToFinish);
    const double effectiveDistance = distanceToFinish * (1.0 - factor);

    return effectiveDistance / m_velocity;
}