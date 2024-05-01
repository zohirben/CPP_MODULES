#include <iostream>
#include <string>
#include "ScalarConverter.hpp"

int main()
{
    std::string input;
    std::cin >> input;
    ScalarConverter::convert(input);
}