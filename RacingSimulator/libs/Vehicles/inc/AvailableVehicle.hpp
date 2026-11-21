#ifndef AVAILABLEVEHICLE_HPP
#define AVAILABLEVEHICLE_HPP

enum class AvailableVehicle
{
    Unknown,            // Неизвестный ТС

    Camel,              // Наземный ТС - Верблюд
    SwiftFootedCamel,   // Наземный ТС - Быстроногий верблюд
    Centaur,            // Наземный ТС - Кентавр
    AllTerrainBoots,    // Наземный ТС - Сапоги-скороходы

    FlyingCarpet,       // Воздушный ТС - Ковёр-самолёт
    Eagle,              // Воздушный ТС - Орёл
    Broom               // Воздушный ТС - Метла
};

#endif