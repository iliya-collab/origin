#ifndef GAME_HPP
#define GAME_HPP
#include <vector>
#include <TypeVehicle.hpp>
#include <AvailableVehicle.hpp>
#include "TypeRace.hpp"

class Game
{
private:

    std::vector<std::pair<TypeVehicle, AvailableVehicle>> m_tableVehicles{}; 

    bool m_exit = false;
    int m_exitCode = EXIT_SUCCESS;
    TypeRace m_race = TypeRace::Unknown;

    double m_distance = 0.0;

    void clearScreen();
    void pauseScreen();
    double inputDistance();

    void showMenuStart();
    void showMenuRecorder();
    void showSubmenuRegisterVehicle();
    void showSubmenuInfoAboutVehicles();
    void showSubmenuRace();

public:

    explicit Game();
    ~Game() = default;

    int loop();

};

#endif