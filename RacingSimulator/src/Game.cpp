#include <iostream>
#include <chrono>
#include <thread>
#include <algorithm>
#include <VehicleTools.hpp>
#include <Vehicles.hpp>
#include "Game.hpp"

Game::Game()
{
    m_tableVehicles.emplace_back(TypeVehicle::Ground,   AvailableVehicle::Camel);
    m_tableVehicles.emplace_back(TypeVehicle::Ground,   AvailableVehicle::SwiftFootedCamel);
    m_tableVehicles.emplace_back(TypeVehicle::Ground,   AvailableVehicle::Centaur);
    m_tableVehicles.emplace_back(TypeVehicle::Ground,   AvailableVehicle::AllTerrainBoots);

    m_tableVehicles.emplace_back(TypeVehicle::Air,      AvailableVehicle::Broom);
    m_tableVehicles.emplace_back(TypeVehicle::Air,      AvailableVehicle::FlyingCarpet);
    m_tableVehicles.emplace_back(TypeVehicle::Air,      AvailableVehicle::Eagle);
}

void Game::clearScreen()
{
    std::this_thread::sleep_for(std::chrono::microseconds(500));
    system("cls");
}

void Game::pauseScreen()
{
    std::cout << "Press any key for continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

void Game::showMenuStart()
{
    std::cout << "##### Welcome to racing simulator! #####\n\n";
    std::cout << "   1. Ground vehicle race\n";
    std::cout << "   2. Air vehicle race\n";
    std::cout << "   3. Mixed vehicle race\n";
    std::cout << "\nSelect the race type: ";
    int race = 0;
    std::cin >> race;

    switch (static_cast<TypeRace>(race))
    {
    case TypeRace::AirRace:
        m_race = TypeRace::AirRace;
        break;
    case TypeRace::GroundRace:
        m_race = TypeRace::GroundRace;
        break;
    case TypeRace::MixedRace:
        m_race = TypeRace::MixedRace;
        break;
    default:
        throw std::runtime_error("Invalid race type");
    }

    std::cout << "\n-------------------------------\n\n";
    m_distance = inputDistance();
}

double Game::inputDistance()
{
    double dist;
    std::cout << "Specify the distance: ";
    std::cin >> dist;
    if (dist <= 0)
        throw std::runtime_error("The distance must be positive");

    return dist;
}

void Game::showSubmenuRegisterVehicle()
{
    bool complete = false;
    while (!complete && !m_exit)
    {
        clearScreen();
        std::cout << "\n*******************************\n";
        std::cout << "Registered vehicles:";
        std::cout << "\n*******************************\n";
        auto vec = RecorderVehicle::instance().getAllRegisteredVehicles();
        if (vec.size() > 0)
        {
            std::cout << "\nRegistered: ";
            std::cout << vec[0]->name();
            for (int i = 1; i < vec.size(); i++)
                std::cout << ", " << vec[i]->name();
            std::cout << "\n";
        }

        std::cout << "\n-------------------------------\n";
        std::cout << typeRaceToString(m_race) << ". Distance: " << m_distance;
        std::cout << "\n-------------------------------\n\n";
        std::cout << "   1. Camel\n";
        std::cout << "   2. SwiftFooted camel\n";
        std::cout << "   3. Centaur\n";
        std::cout << "   4. All terrain boots\n";
        std::cout << "   5. Flying carpet\n";
        std::cout << "   6. Eagle\n";
        std::cout << "   7. Broom\n";
        std::cout << "   0. Complete registration\n";
        
        std::cout << "\nSelect a vehicle option, or enter 0 to finish: ";
        int v = 0;
        std::cin >> v;

        if (v == 0)
        {
            complete = true;
            continue;
        }

        AvailableVehicle vehicle = static_cast<AvailableVehicle>(v);
        for (const auto& p : m_tableVehicles)
        {
            if (p.second == vehicle)
            {
                if ((m_race == TypeRace::AirRace || m_race == TypeRace::MixedRace) && p.first == TypeVehicle::Air)
                {
                    RecorderVehicle::instance().registerVehicle(AirVehicleCreator::create(vehicle));
                    break;
                }
                else if ((m_race == TypeRace::GroundRace || m_race == TypeRace::MixedRace) && p.first == TypeVehicle::Ground)
                {
                    RecorderVehicle::instance().registerVehicle(GroundVehicleCreator::create(vehicle));
                    break;
                }
                else
                {
                    std::cerr << "Attempt to register an incorrect vehicle type\n";
                    pauseScreen();
                    break;
                }
            }
        }

    }
}

void Game::showSubmenuInfoAboutVehicles()
{
    clearScreen();
    std::cout << "\n*******************************\n";
    std::cout << "Information about registered vehicles:";
    std::cout << "\n*******************************\n\n";
    auto vec = RecorderVehicle::instance().getAllRegisteredVehicles();

    if (vec.size() == 0)
        std::cout << " !!! No registered vehicles\n";
    else 
        for (const auto& v : vec)
            std::cout << v->info() << std::endl;
    pauseScreen();
}

void Game::showSubmenuRace()
{
    clearScreen();
    std::cout << "\n*******************************\n";
    std::cout << "Race results:";
    std::cout << "\n*******************************\n\n";
    const auto& vec =  RecorderVehicle::instance().getAllRegisteredVehicles();
    std::vector<std::pair<std::string, double>> results;

    std::transform(vec.begin(), vec.end(), std::back_inserter(results), 
        [this](IVehicle* v) -> std::pair<std::string, double> { return { v->name(), v->run(m_distance) };  });
    
    std::sort(results.begin(), results.end(), 
        [](const auto& a, const auto& b) { return a.second < b.second; });

    int n = 0;
    for (auto [name, time] : results)
        std::cout << ++n << ". " << name << " : " << time << "s\n";

    std::cout << "\n-------------------------------\n\n";
    std::cout << "0. Exit\n";
    std::cout << "1. Conduct another one\n";
    std::cout << "\nSelect an action: ";
    int action = 0;
    std::cin >> action;
    switch (action)
    {
    case 0:
        m_exit = true;
        break;
    case 1:
        break;
    default:
        throw std::runtime_error("Unknown action type");
    } 
}

void Game::showMenuRecorder()
{
    bool exit = false;

    while (!exit && !m_exit)
    {
        clearScreen();
        std::cout << "\n*******************************\n";
        std::cout << "You must register at least 2 vehicles";
        std::cout << "\n*******************************\n\n";
        std::cout << "   0. Exit\n";
        std::cout << "   1. Register a vehicle\n";
        std::cout << "   2. View registered vehicles\n";
        std::cout << "   3. Start race\n";
        std::cout << "\nSelect an action: ";
        int action = 0;
        std::cin >> action;

        switch (action)
        {
        case 0:
            m_exit = true;
            break;
        case 1:
            showSubmenuRegisterVehicle();
            break;
        case 2:
            showSubmenuInfoAboutVehicles();
            break;
        case 3:
            showSubmenuRace();
            break;
        default:
            throw std::runtime_error("Unknown action type");
        }
    }
    pauseScreen();
}

int Game::loop()
{
    while (!m_exit)
    {
        clearScreen();
        try
        {
            showMenuStart();
            showMenuRecorder();
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            m_exit = true;
            m_exitCode = EXIT_FAILURE;
            pauseScreen();
        }
    }
    return m_exitCode;
}