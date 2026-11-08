#ifndef LEAVER_HPP
#define LEAVER_HPP

#ifdef BUILDING_LEAVER_DLL
#define API __declspec(dllexport)
#else
#define API __declspec(dllimport)
#endif

class API Leaver
{
public:
    explicit Leaver() = default;
    ~Leaver() = default;

    void leaver(std::string_view name);
};

#endif