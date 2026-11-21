#ifndef BROOM_HPP
#define BROOM_HPP
#include "BaseAirVehicle.hpp"

class Broom : public BaseAirVehicle
{
public:
    explicit Broom();
    
    std::string info() const override;
    std::string name() const override;

private:
    double reductionFactorFor(double distance) const override;
};

#endif