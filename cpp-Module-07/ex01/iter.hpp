#pragma once

#include <iostream>
#include <string>
#include <iomanip>

template <typename T>
void print(T x)
{
    std::cout << x << " ";
}

template <>
void print<double>(double x)
{
    std::cout << std::fixed << std::setprecision(2) << x << " ";
}


void to_upper(char &c)
{
    c = std::toupper(static_cast<unsigned char>(c));
}


template <typename T, typename Func>
void iter(T *array, int size, Func func)
{
    for (int i = 0; i < size; i++)
    {
        func(array[i]);
    }
}