#ifndef BASEVEHICLE_HPP
#define BASEVEHICLE_HPP
#include "IVehicle.hpp"

class BaseVehicle : public IVehicle
{
public:

    explicit BaseVehicle(TypeVehicle type, AvailableVehicle vehicle, double velocity) 
        : m_type{type}, m_vehicle{vehicle}, m_velocity{velocity} {}
        
    virtual ~BaseVehicle() = default;

    AvailableVehicle vehicle() const override { return m_vehicle; }
    TypeVehicle type() const override { return m_type; }
    std::string info() const override;
    
protected:
    double m_velocity = 0.0;

private:
    AvailableVehicle m_vehicle = AvailableVehicle::Unknown;
    TypeVehicle m_type = TypeVehicle::Unknown;

};

#endif