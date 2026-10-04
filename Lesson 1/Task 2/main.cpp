#include <iostream>
#include <fstream>
#include <list>

class Address 
{
private:

    std::string m_nameCity{};
    std::string m_nameStreet{};
    int m_houseNumber{};
    int m_apartmentNumber{};

public:

    std::string getNameCity() const { return m_nameCity; };
    std::string getNameStreet() const { return m_nameStreet; };
    int getHouseNumber() const { return m_houseNumber; };
    int getApartmentNumber() const { return m_apartmentNumber; };

    void setNameCity(std::string_view str) { m_nameCity = str; };
    void setNameStreet(std::string_view str) { m_nameStreet = str; };
    void setHouseNumber(int val) { m_houseNumber = val; };
    void setApartmentNumber(int val) { m_apartmentNumber = val; };

    friend std::ostream& operator << (std::ostream& os, const Address& addr);
    bool operator > (const Address& other) const { return this->getNameCity() < other.getNameCity(); }

};

std::ostream& operator << (std::ostream& os, const Address& addr)
{
    os << addr.getNameCity() << ", " << addr.getNameStreet() << ", " 
        << addr.getHouseNumber() << ", " << addr.getApartmentNumber();
    return os;
}

class AddressManager 
{
private:

    AddressManager() = default;
    std::list<Address> m_addrs{};

public:

    static AddressManager& instance() 
    {
        static AddressManager manager;
        return manager;
    }

    bool readAddresses(std::ifstream& fin, size_t count)
    {
        if (!fin.is_open())
            return false;

        m_addrs.clear();

        while (!fin.eof())
        {
            Address addr{};

            std::string city;
            std::string street;
            int house;
            int apartment;
            fin >> city;
            fin >> street;
            fin >> house;
            fin >> apartment;

            addr.setNameCity(city);
            addr.setNameStreet(street);
            addr.setHouseNumber(house);
            addr.setApartmentNumber(apartment);

            m_addrs.push_back(addr);
        } 
        
        return true;
    }

    void sortAddresses()
    {
        m_addrs.sort([](const Address& addr1, const Address& addr2) { return addr1 > addr2; });
    }

    void writeAddresses(std::ofstream& fout) 
    {
        for (const auto& addr : m_addrs)
            fout << addr << std::endl;
    }

};

int main() 
{
    std::ifstream fin;
    std::ofstream fout;
    size_t count{};

    fin.open("in.txt");
    if (!fin.is_open())
        std::cout << "Could not open the file \'" << "in.txt" << "\'" << std::endl;

    fin >> count;

    auto& manager = AddressManager::instance();
    if (!manager.readAddresses(fin, count))
        std::cout << "Could not read the file" << std::endl;

    fin.close();

    manager.sortAddresses();

    fout.open("out.txt");

    fout << count << std::endl;
    manager.writeAddresses(fout);

    fout.close();

    return EXIT_SUCCESS;
}