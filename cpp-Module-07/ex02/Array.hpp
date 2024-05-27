#pragma once

#include <iostream>

template <typename T>
class Array
{
private:
    T *array;
    unsigned int len;

public:

    
    // why i defined the methods of this template class here?
    // i have problem in tpp configuration, to define them in cpp file the compiler needs to know where's the declaration and the definition
    // and if i include both files into each other it will cause a linker problem.
    Array() : array(NULL), len(0) {}

    Array(unsigned int n)
    {
        // parentheses () at the end values the allocated memory so it initializes all elements to zero by default
        // but here is a class type so if its something not classic type it will go to its default constructor and use it
        // we call it default-constructed
        // the behavior of new T[n]() with a complex type T depends on the default constructor of T.
        array = new T[n]();
        len = n;
    }

    Array(const Array &other)
    {
        len = other.len;
        array = new T[len]();
        for (unsigned int i = 0; i < len; i++)
        {
            array[i] = other.array[i];
        }
    }
    Array &operator=(const Array &other)
    {
        if (this != &other)
        {
            len = other.len;
            delete[] array;
            array = new T[len]();
            for (unsigned int i = 0; i < len; i++)
            {
                array[i] = other.array[i];
            }
            return *this;
        }
    }
    ~Array()
    {
        delete[] array;
    }

    T&operator[](unsigned int index)
    {
        if (index >= len)
            throw std::out_of_range("Index out of range!");
        return array[index];
    }

    unsigned int size()
    {
        return this->len;
    }
};
