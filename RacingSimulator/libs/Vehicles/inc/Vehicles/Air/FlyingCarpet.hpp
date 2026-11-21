#ifndef FLYINGCARPET_HPP
#define FLYINGCARPET_HPP
#include "BaseAirVehicle.hpp"

class FlyingCarpet : public BaseAirVehicle
{
public:
    explicit FlyingCarpet();

    std::string info() const override;
    std::string name() const override;

private:
    double reductionFactorFor(double distance) const override;
};

#endif