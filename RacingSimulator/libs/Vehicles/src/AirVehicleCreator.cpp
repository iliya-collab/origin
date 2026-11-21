#include "VehicleException.hpp"
#include "Vehicles/Air/Broom.hpp"
#include "Vehicles/Air/Eagle.hpp"
#include "Vehicles/Air/FlyingCarpet.hpp"
#include "AirVehicleCreator.hpp"

std::unique_ptr<IVehicle> AirVehicleCreator::create(AvailableVehicle vehicle)
{
    switch (vehicle)
    {
    case AvailableVehicle::FlyingCarpet:
        return std::make_unique<FlyingCarpet>();
    case AvailableVehicle::Eagle:
        return std::make_unique<Eagle>();
    case AvailableVehicle::Broom:
        return std::make_unique<Broom>();
    default:
        throw InvalidTypeVehicleException("The transport is not air transport or is not in the list of available options");
    }
}