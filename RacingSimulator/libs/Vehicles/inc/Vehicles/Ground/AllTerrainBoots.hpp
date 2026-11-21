#ifndef ALLTERRAINBOOTS_HPP
#define ALLTERRAINBOOTS_HPP
#include "BaseGroundVehicle.hpp"

class AllTerrainBoots : public BaseGroundVehicle
{
public:
    explicit AllTerrainBoots();

    std::string info() const override;
    std::string name() const override;

private:
    double restDurationFor(int index) const override;
};

#endif