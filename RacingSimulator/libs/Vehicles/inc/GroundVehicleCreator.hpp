#ifndef GROUNDVEHICLECREATOR_HPP
#define GROUNDVEHICLECREATOR_HPP
#include <memory>
#include "IVehicle.hpp"

class GroundVehicleCreator final
{
public:
    static std::unique_ptr<IVehicle> create(AvailableVehicle vehicle);

};

#endif