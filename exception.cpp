#include <string>
#include <iostream>
#include <exception>

class SomethingWentWrongException : public std::exception
{

public:
    const char * what() const noexcept
    {
        return "Something went wrong!";
    }
};

int main()
{
    std::cout << "Example 1 - throw a standard string\n";

    unsigned int bad = 1;

    try {
        if (bad)
            throw std::string("Something went wrong\n");
    } catch (std::string e) {
        std::cerr << e;
    }

    std::cout << "Example 2 - throw an exception class\n";

    try {
        if (bad)
            throw SomethingWentWrongException();
    } catch (SomethingWentWrongException & e) {
        std::cerr << e.what();
    }

    return 0;
}
