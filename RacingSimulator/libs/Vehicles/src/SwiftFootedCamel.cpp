#include <string>
#include "Vehicles/Ground/SwiftFootedCamel.hpp"

SwiftFootedCamel::SwiftFootedCamel() : BaseGroundVehicle(AvailableVehicle::SwiftFootedCamel, 40.0, 10.0) {};

std::string SwiftFootedCamel::name() const
{
    return "Swift footed camel";
}

std::string SwiftFootedCamel::info() const
{
    return name() + ": " + BaseGroundVehicle::info()
         + ", rest: 5h, 6.5h, then 8h";
}

double SwiftFootedCamel::restDurationFor(int index) const
{
    if (index == 0) 
        return 5.0;
    if (index == 1) 
        return 6.5;
    return 8.0;
}