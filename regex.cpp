#include <regex>
#include <iostream>
#include <vector>
#include <map>

int main(int argc, char ** argv)
{
    std::map<std::string, std::pair<std::string, std::string>> options;
    std::regex isOptionWithEqual("^--([^-].+)=([^-].+)$");
    std::regex isAliasOption("^-{1}([^-]{1})$");
    std::regex isOption("^--([^-].+)$");
    std::regex isOptionValue("^[^-](.+)$");
    std::smatch matchedOption;
    std::smatch matchedOptionWithEqual;
    std::smatch matchedOptionAlias;
    std::smatch matchedOptionValue;
    std::string command;
    
    std::vector<std::string> arguments(argv + 1, argv + argc);

    command = arguments[0];

    for (std::size_t i = 1; i != arguments.size(); ++i)
    {
        // Is it an option with = sign ? (i.e --option=value)
        if (std::regex_search(arguments[i], matchedOptionWithEqual, isOptionWithEqual)) {
            std::string optionKey;
            std::string optionValue;


            optionKey = matchedOptionWithEqual[1].str();
            optionValue = matchedOptionWithEqual[2].str();
            
            options[std::to_string(i)] = std::pair<std::string, std::string>(optionKey, optionValue);
            continue;
        }

        // Is it an option which is an alias ? (i.e -h)
        if (std::regex_search(arguments[i], matchedOptionAlias, isAliasOption)) {
            
            // Is it the last argument ? if so treat it as a flag.
            if (i+1 >= arguments.size()) {
                options[matchedOptionAlias[1].str()] = std::pair<std::string, std::string>("none", "true");
            }
            // Is the next value is valid option value ? (=not an option).
            else if (std::regex_search(arguments[i+1], matchedOptionValue, isOptionValue)) {
                options[matchedOptionAlias[1].str()] = std::pair<std::string, std::string>("none", matchedOptionValue.str());   
                i++; 
            }
            // otherwise, treat the option as a flag.
            else
            {
                options[matchedOptionAlias[1].str()] = std::pair<std::string, std::string>("none", "true");
            }

            continue;
        }

        // Is it a regular option ? (i.e --option value)
        if (std::regex_search(arguments[i], matchedOption, isOption)) {

            // Is it the last argument ? if so treat it as a flag.
            if (i+1 >= arguments.size()) {
                options[std::to_string(i)] = std::pair<std::string, std::string>(matchedOption[1].str(), "true");
            }
            // Is the next value is valid option value ? (=not an option).
            else if (std::regex_search(arguments[i+1], matchedOptionValue, isOptionValue)) {
                options[std::to_string(i)] = std::pair<std::string, std::string>(matchedOption[1].str(), matchedOptionValue.str());   
                i++; 
            }
            // otherwise, treat the option as a flag.
            else
            {
                options[std::to_string(i)] = std::pair<std::string, std::string>(matchedOption[1].str(), "true");
            }
            
            continue;
        }
    }

    std::cout << "command: " << command << '\n';

    for (auto & option : options)
    {
        std::cout << "option alias: " << option.first << '\n';
        std::cout << "option key: " << option.second.first << '\n';
        std::cout << "option value: " << option.second.second << '\n';

        std::cout << "#####################" << '\n';
    }
}

