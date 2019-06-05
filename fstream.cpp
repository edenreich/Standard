#include <iostream>
#include <fstream>

int main()
{
    std::string filename = "fixtures/template.h";

    std::ifstream input;

    input.open(filename);

    while (!input.eof())
    {
        std::string description;

        std::getline(input, description, '\n');

        std::cout << "line: " << description << std::endl;
    }

    input.close();

    return 0;
}