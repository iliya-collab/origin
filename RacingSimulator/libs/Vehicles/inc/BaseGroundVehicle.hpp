#ifndef BASEGROUNDVEHICLE_HPP
#define BASEGROUNDVEHICLE_HPP
#include "BaseVehicle.hpp"

class BaseGroundVehicle : public BaseVehicle
{
public:

    explicit BaseGroundVehicle(AvailableVehicle vehicle, double velocity, double timeUntilRest);
    virtual ~BaseGroundVehicle() = default;

    virtual double restDurationFor(int index) const = 0;
    double run(double distanceToFinish) override;
    std::string info() const override;

protected:
    double m_timeUntilRest = 0.0;
};

#endif