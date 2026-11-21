#ifndef CAMEL_HPP
#define CAMEL_HPP
#include "BaseGroundVehicle.hpp"

class Camel final : public BaseGroundVehicle
{
private:
    double restDurationFor(int index) const override;
    
public:
    explicit Camel();

    std::string info() const override;
    std::string name() const override;

};

#endif