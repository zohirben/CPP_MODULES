#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string &input)
{
    if (input.length() == 1 && std::isalpha(input[0]))
    {
        std::cout << "this is a character!" << std::endl;
        ConvertChar(input);
    }
    // else if (std::all_of(input.begin(), input.end(), ::isalpha))
    //     std::cout << "this is a string!" << std::endl;
    else if (std::all_of(input.begin(), input.end(), ::isdigit))
    {
        std::cout << "this is an integer!" << std::endl;
        ConvertInt(input);
    }
    else if (input.find('.') != std::string::npos)
    {
        std::string::size_type pos = input.find_first_of('.');
        if (pos != std::string::npos && pos != 0 &&
            std::all_of(input.begin(), input.begin() + pos, ::isdigit) &&
            std::all_of(input.begin() + pos + 1, input.end() - 1, ::isdigit) && input.back() == 'f')
        {
            std::cout << "this is a float!" << std::endl;
            ConvertFloat(input);
        }
        else if (pos != std::string::npos && pos != 0 &&
                 std::all_of(input.begin(), input.begin() + pos, ::isdigit) &&
                 std::all_of(input.begin() + pos + 1, input.end(), ::isdigit))
        {
            std::cout << "this is a double!" << std::endl;
            ConvertDouble(input);
        }
        else
            std::cout << "this is trash! trying to sneak into float" << std::endl;
    }
    else
    {
        std::cout << "wtf is this!" << std::endl;
    }
}
