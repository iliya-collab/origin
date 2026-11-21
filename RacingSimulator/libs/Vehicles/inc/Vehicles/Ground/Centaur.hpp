#ifndef CENTAUR_HPP
#define CENTAUR_HPP
#include "BaseGroundVehicle.hpp"

class Centaur final : public BaseGroundVehicle
{
public:
    explicit Centaur();

    std::string info() const override;
    std::string name() const override;

private:
    double restDurationFor(int /*index*/) const override;
};



#endif