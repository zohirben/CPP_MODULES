#pragma once

#include <iostream>

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
