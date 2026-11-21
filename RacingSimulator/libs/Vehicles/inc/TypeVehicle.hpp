#ifndef TYPEVEHICLE_HPP
#define TYPEVEHICLE_HPP

enum class TypeVehicle 
{
    Air,
    Ground,
    Unknown
};

inline std::string typeToString(TypeVehicle t)
{
    switch (t)
    {
        case TypeVehicle::Ground:  return "Ground";
        case TypeVehicle::Air:     return "Air";
        case TypeVehicle::Unknown: return "Unknown";
    }
    return "Unknown";
}


#endif