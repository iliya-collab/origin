#include "VehicleException.hpp"
#include "Vehicles/Ground/AllTerrainBoots.hpp"
#include "Vehicles/Ground/Camel.hpp"
#include "Vehicles/Ground/SwiftFootedCamel.hpp"
#include "Vehicles/Ground/Centaur.hpp"
#include "GroundVehicleCreator.hpp"

std::unique_ptr<IVehicle> GroundVehicleCreator::create(AvailableVehicle vehicle)
{
    switch (vehicle)
    {
    case AvailableVehicle::Camel:
        return std::make_unique<Camel>();
    case AvailableVehicle::SwiftFootedCamel:
        return std::make_unique<SwiftFootedCamel>();
    case AvailableVehicle::Centaur:
        return std::make_unique<Centaur>();
    case AvailableVehicle::AllTerrainBoots:
        return std::make_unique<AllTerrainBoots>();
    default:
        throw InvalidTypeVehicleException("The transport is not ground-based or is not in the list of available options");
    }
}