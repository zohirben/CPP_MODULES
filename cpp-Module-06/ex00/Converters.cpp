#include "ScalarConverter.hpp"

void printAll(char c, int i, float f, double d)
{
    if (std::isprint(c) )
        std::cout << "char: '" << c << "'\n";
    else if (std::isnan(f) || std::isinf(f))
        std::cout << "char: impossible" << c << std::endl;
    else
        std::cout << "char: Non Displayable" << std::endl;
    if (std::isnan(d) || std::isinf(d))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << i << std::endl;
    std::cout << std::setprecision(1);
    std::cout << "float: " << std::fixed << f << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}

void ConvertChar(std::string input)
{
    char c;
    int i;
    float f;
    double d;
    char character = input[0];

    c = character;
    i = static_cast<int>(character);
    f = static_cast<float>(character);
    d = static_cast<double>(character);

    printAll(c, i, f, d);
}

void ConvertInt(std::string input)
{
    char c;
    int i;
    float f;
    double d;
    int numInt;

    try
    {
        numInt = std::stoi(input);
    }
    catch (std::out_of_range &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
        return;
    }

    c = static_cast<char>(numInt);
    i = numInt;
    f = static_cast<float>(numInt);
    d = static_cast<double>(numInt);

    printAll(c, i, f, d);
}

void ConvertFloat(std::string input)
{
    char c;
    int i;
    float f;
    double d;
    float numFloat = std::stof(input);

    c = static_cast<char>(numFloat);
    i = static_cast<int>(numFloat);
    f = numFloat;
    d = static_cast<double>(numFloat);

    printAll(c, i, f, d);
}

void ConvertDouble(std::string input)
{
    char c;
    int i;
    float f;
    double d;
    double numDouble = std::stod(input);

    c = static_cast<char>(numDouble);
    i = static_cast<int>(numDouble);
    f = static_cast<float>(numDouble);
    d = numDouble;

    printAll(c, i, f, d);
}
