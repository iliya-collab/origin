#ifndef TYPERACE_HPP
#define TYPERACE_HPP

enum class TypeRace {
    Unknown,
    GroundRace,
    AirRace,
    MixedRace
};

inline std::string typeRaceToString(TypeRace tr)
{
    switch (tr)
    {
    case TypeRace::GroundRace:
        return "Ground Race";
    case TypeRace::AirRace:
        return "Air Race";
    case TypeRace::MixedRace:
        return "Mixed Race";
    default:
        return "Unknown";
    }
}

/*inline bool isSame(TypeRace tr, TypeVehicle tv)
{
    switch (tr)
    {
    case TypeRace::GroundRace:
        return tv == TypeVehicle::Ground;
    case TypeRace::AirRace:
        return tv == TypeVehicle::Air;
    case TypeRace::MixedRace:
        return tv != TypeVehicle::Unknown;
    default:
        return tv == TypeVehicle::Unknown;
    }
}*/

#endif