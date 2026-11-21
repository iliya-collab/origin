#ifndef RECORDERVEHICLE_HPP
#define RECORDERVEHICLE_HPP
#include <vector>
#include <map>
#include <set>
#include <memory>

class RecorderVehicle final
{
private:

    explicit RecorderVehicle() = default;
    RecorderVehicle(const RecorderVehicle&) = delete;
    RecorderVehicle& operator=(const RecorderVehicle&) = delete;

    std::map<TypeVehicle, std::vector<std::unique_ptr<IVehicle>>> m_registeredVehicles{};
    std::set<AvailableVehicle> m_usedVehicles{};

public:

    static RecorderVehicle& instance();

    void registerVehicle(std::unique_ptr<IVehicle> vehicle);
    
    std::vector<IVehicle*> getRegisteredVehicles(TypeVehicle type) const;
    std::vector<IVehicle*> getAllRegisteredVehicles() const;

    size_t numberOfRegisteredVehicles(TypeVehicle type) const;
    size_t numberOfAllRegisteredVehicles() const;

};

#endif