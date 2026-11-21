#include "IVehicle.hpp"
#include "VehicleException.hpp"
#include "RecorderVehicle.hpp"

RecorderVehicle& RecorderVehicle::instance()
{
    static RecorderVehicle recorder;
    return recorder;
}

void RecorderVehicle::registerVehicle(std::unique_ptr<IVehicle> vehicle)
{
    if (!vehicle)
    throw InvalidRegisteredVehicleException(
        "The vehicle does not exist");
        
    IVehicle* v = vehicle.get();
    TypeVehicle type = v->type();
    
    if (type == TypeVehicle::Unknown)
        throw InvalidRegisteredVehicleException(
            "It is not possible to register a vehicle with an unknown type");

    if (!m_usedVehicles.insert(v->vehicle()).second)
        throw InvalidRegisteredVehicleException(
            "This vehicle has already been registered");
        
    m_registeredVehicles[type].push_back(std::move(vehicle));
}

std::vector<IVehicle*> RecorderVehicle::getRegisteredVehicles(TypeVehicle type) const
{
    if (type == TypeVehicle::Unknown)
        throw InvalidRegisteredVehicleException(
            "Cannot obtain a vehicle with an unknown type");

    std::vector<IVehicle*> result;
    auto it = m_registeredVehicles.find(type);
    if (it == m_registeredVehicles.end())
        return result;

    result.reserve(it->second.size());
    for (const auto& v : it->second)
        result.push_back(v.get());
    return result;
}

std::vector<IVehicle*> RecorderVehicle::getAllRegisteredVehicles() const
{
    std::vector<IVehicle*> result;
    for (const auto& [type, vec] : m_registeredVehicles)
        for (const auto& v : vec)
            result.push_back(v.get());
    return result;
}

size_t RecorderVehicle::numberOfRegisteredVehicles(TypeVehicle type) const
{
    return m_registeredVehicles.at(type).size();
}

size_t RecorderVehicle::numberOfAllRegisteredVehicles() const
{
    return m_registeredVehicles.at(TypeVehicle::Air).size() +
            m_registeredVehicles.at(TypeVehicle::Ground).size();
}
