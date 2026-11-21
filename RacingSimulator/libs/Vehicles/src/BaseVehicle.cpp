#include <sstream>
#include "BaseVehicle.hpp"

std::string BaseVehicle::info() const
{
    std::ostringstream os;
    os << typeToString(m_type) << " " << m_velocity << " km/h";
    return os.str();
}