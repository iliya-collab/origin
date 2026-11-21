#include <string>
#include "Vehicles/Ground/AllTerrainBoots.hpp"

AllTerrainBoots::AllTerrainBoots() : BaseGroundVehicle(AvailableVehicle::AllTerrainBoots, 6.0, 60.0) {};

std::string AllTerrainBoots::name() const
{
    return "All terrain boots";
}

std::string AllTerrainBoots::info() const
{
    return name() + ": " + BaseGroundVehicle::info()
         + ", rest: 10h (first), then 5h";
}

double AllTerrainBoots::restDurationFor(int index) const
{
    return index == 0 ? 10.0 : 5.0;
}