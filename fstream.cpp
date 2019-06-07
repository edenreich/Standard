#include <iostream>
#include <fstream>
#include <regex>

int main()
{
    std::string filename = "fixtures/template.h";

    std::ifstream handle;

    std::cout << "# First example: \n";
    handle.open(filename);

    while (!handle.eof())
    {
        std::string line;

        std::getline(handle, line, '\n');

        std::cout << "line: " << line << std::endl;
    }

    // Don't forget to close the file when done
    handle.close();

    std::cout << "################################################\n";
    std::cout << "# Second example, parsing docblocks anotations: \n";

    std::string filename2 = "fixtures/template.h";
    std::ifstream handle2;

    char anotation = '@';

    handle2.open(filename2);

    std::pair<std::string, std::string> name;
    std::pair<std::string, std::string> description;

    unsigned int anotationCount = 0;

    // Second example
    while (!handle2.eof())
    {
        std::string line;
        std::getline(handle2, line, '\n');

        for (char & letter: line) {
            if (letter != anotation) {
                continue;
            }

            anotationCount++;

            // @name ewfwefwef
            std::smatch matches;
            std::regex nameRegEx("(@name)\\s(.*)");
            std::regex descriptionRegEx("(@description)\\s(.*)");

            while (std::regex_search(line, matches, nameRegEx)) {
                name.first = matches.str(1);
                name.second = matches.str(2);
                break;
            }

            while (std::regex_search(line, matches, descriptionRegEx)) {
                description.first = matches.str(1);
                description.second = matches.str(2);
                break;
            }

            break;
        }
    }

    std::cout << "There were " << anotationCount << " anotations in this document" << std::endl;
    std::cout << "The name key: " << name.first << ". And the name value is: " << name.second << std::endl;
    std::cout << "The description key: " << description.first << ". And the description value is: " << description.second << std::endl;

    handle2.close();

    return 0;
}