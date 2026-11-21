#include <cmath>
#include <sstream>
#include "BaseGroundVehicle.hpp"

BaseGroundVehicle::BaseGroundVehicle(AvailableVehicle vehicle, double velocity, double timeUntilRest)
    : BaseVehicle(TypeVehicle::Ground, vehicle, velocity), m_timeUntilRest{timeUntilRest} {};

std::string BaseGroundVehicle::info() const
{
    std::ostringstream os;
    os << BaseVehicle::info() << ", rest every " << m_timeUntilRest << "h";
    return os.str();
}

double BaseGroundVehicle::run(double distanceToFinish)
{
    if (m_velocity <= 0.0) 
        return std::numeric_limits<double>::infinity();
    if (distanceToFinish <= 0.0)   
        return 0.0;
    if (m_timeUntilRest <= 0.0) 
        return distanceToFinish / m_velocity;

    const double travelTime = distanceToFinish / m_velocity;
    const int restCount = static_cast<int>(std::ceil(travelTime / m_timeUntilRest)) - 1;

    double total = travelTime;
    for (int i = 0; i < restCount; ++i)
        total += restDurationFor(i);
        
    return total;
}