#ifndef IVEHICLE_HPP
#define IVEHICLE_HPP
#include <string>
#include "AvailableVehicle.hpp"
#include "TypeVehicle.hpp"

class IVehicle 
{
public:
    explicit IVehicle() = default;
    virtual ~IVehicle() = default;

    // Выдает информацию о ТС ( <имя>: <тип ТС> <скорость> ...)
    virtual std::string info() const = 0;
    // Возвращает название ТС
    virtual std::string name() const = 0;
    // Возвращает чем является данное TC
    virtual AvailableVehicle vehicle() const = 0;
    // Возвращает какого типа данный TC
    virtual TypeVehicle type() const = 0;
    // ТС проходит заданное расстояние и выдает время финиширования 
    virtual double run(double distanceToFinish) = 0;
};

#endif // IVEHICLE_HPP