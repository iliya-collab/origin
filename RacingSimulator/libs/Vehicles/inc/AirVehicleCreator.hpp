#ifndef AIRVEHICLECREATOR_HPP
#define AIRVEHICLECREATOR_HPP
#include <memory>
#include "IVehicle.hpp"

class AirVehicleCreator final
{    
public:    
    static std::unique_ptr<IVehicle> create(AvailableVehicle vehicle);
};

#endif