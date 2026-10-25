#include <iostream>

class bad_length : public std::exception
{
public:
    const char* what() const noexcept override { return "You entered a word of a forbidden length! Goodbye."; }
};

int function(std::string str, int forbidden_length)
{
    const auto len = str.size();
    if (len == forbidden_length)
        throw bad_length();
    return len;
}

int main()
{
    int forbidden_length;
    std::cout << "Input forbidden length: ";
    std::cin >> forbidden_length;

    bool isExit = false;
    std::string str;
    while (!isExit)
    {
        std::cout << "Input string: ";
        std::cin >> str;
        try
        {
            const auto len = function(str, forbidden_length);
            std::cout << "The length of the word \"" << str << "\" is " << len << std::endl;
        }
        catch(const bad_length& e)
        {
            std::cerr << e.what() << '\n';
            isExit = true;
        }
        
    }
    

    return EXIT_SUCCESS;
}