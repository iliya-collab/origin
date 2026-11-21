#ifndef SWIFTFOOTEDCAMEL_HPP
#define SWIFTFOOTEDCAMEL_HPP
#include "BaseGroundVehicle.hpp"

class SwiftFootedCamel final : public BaseGroundVehicle
{
private:
    double restDurationFor(int index) const override;

public:
    explicit SwiftFootedCamel();

    std::string info() const override;
    std::string name() const override;

};

#endif