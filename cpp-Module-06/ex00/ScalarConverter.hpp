#pragma once

#include <iostream>
#include "Converters.hpp"
#include <cmath>
class ScalarConverter
{
    private:
    public:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter& operator=(const ScalarConverter &other);
        ~ScalarConverter();
public:
    static void convert(const std::string &input);
};
