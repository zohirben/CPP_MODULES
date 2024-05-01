#include "ScalarConverter.hpp"


void ConvertChar(std::string input)
{
    char c = input[0];
    std::cout << c << std::endl;
    
}

void ConvertInt(std::string input)
{
    int numInt = std::stoi(input);
    std::cout << numInt << std::endl;
    
}

void ConvertFloat(std::string input)
{
    float numFloat = std::stof(input);
    std::cout << numFloat << std::endl;
    
}

void ConvertDouble(std::string input)
{
    double numDouble = std::stod(input);
    std::cout << numDouble << std::endl;

}

void printAll(char c, int x, float y, double z)
{
    std::cout << "char: " << c << std::endl;
    std::cout << "int: " << x << std::endl;
    std::cout << "float: " << y << std::endl;
    std::cout << "double: " << z << std::endl;
}