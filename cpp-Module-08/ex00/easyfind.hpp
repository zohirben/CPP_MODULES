#pragma once

#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
// used const& here cuz i dont want to make a copy of a data that can be large and heavy on performance
// so used & to take reference of object and const to ensure that the function won't modify the object. lighter & safer :D
void    easyfind(const T& containers, int x)
{
    // std::find returns an iterator pointing to the first element that equals to x
    typename T::const_iterator found = std::find(containers.begin(), containers.end(), x);
    // if the value is found, found is an iterator pointing to the value, else found is equal to containers.end()
    // containers.end() is a special iterator that points one past the end of the container which is not an actual element.
    if (found != containers.end())
    {
        std::cout << "Element " << *found << " is found in the container\n";
    }
    else
    {
        throw std::runtime_error("Element not found");
    }
}