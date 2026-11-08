#ifndef GREETER_HPP
#define GREETER_HPP

class Greeter
{
public:
    explicit Greeter() = default;
    ~Greeter() = default;

    void greet(std::string_view name);
};


#endif