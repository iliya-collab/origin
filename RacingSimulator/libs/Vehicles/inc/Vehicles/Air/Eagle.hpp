#ifndef EAGLE_HPP
#define EAGLE_HPP
#include "BaseAirVehicle.hpp"

class Eagle : public BaseAirVehicle
{
public:
    explicit Eagle();

    std::string info() const override;
    std::string name() const override;

private:
    double reductionFactorFor(double /*distance*/) const override;
};

#endif