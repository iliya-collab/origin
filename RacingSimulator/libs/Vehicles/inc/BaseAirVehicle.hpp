#ifndef BASEAIRVEHICLE_HPP
#define BASEAIRVEHICLE_HPP
#include "BaseVehicle.hpp"

class BaseAirVehicle : public BaseVehicle
{
public:

    explicit BaseAirVehicle(AvailableVehicle vehicle, double velocity);

    virtual ~BaseAirVehicle() = default;

    virtual double reductionFactorFor(double distance) const = 0;
    double run(double distanceToFinish) override;

};

#endif