#include "ScalarConverter.hpp"

void ConvertInt(std::string input)
{
    char c;
    int i;
    float f;
    double d;
    int numInt = std::stoi(input);
    std::cout << numInt << std::endl;
    
    c = static_cast<char>(numInt);
    i = static_cast<int>(numInt);
    f = static_cast<float>(numInt);
    d = static_cast<double>(numInt);

    
}

void ConvertFloat(std::string input)
{
    char c;
    int i;
    float f;
    double d;
    float numFloat = std::stof(input);
    std::cout << numFloat << std::endl;
    
    c = static_cast<char>(numFloat);
    i = static_cast<int>(numFloat);
    f = static_cast<float>(numFloat);
    d = static_cast<double>(numFloat);

    
}

void ConvertDouble(std::string input)
{
    char c;
    int i;
    float f;
    double d;
    double numDouble = std::stod(input);
    std::cout << numDouble << std::endl;

    c = static_cast<char>(numDouble);
    i = static_cast<int>(numDouble);
    f = static_cast<float>(numDouble);
    d = static_cast<double>(numDouble);

    
}

void printAll(char c, int x, float y, double z)
{
    std::cout << "char: " << c << std::endl;
    std::cout << "int: " << x << std::endl;
    std::cout << "float: " << y << std::endl;
    std::cout << "double: " << z << std::endl;
}