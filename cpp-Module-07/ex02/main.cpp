#include "Array.hpp"

int main()
{
    {
        try
        {

            Array<int> simple(10);

            // making sure the variable is initialized by default
            std::cout << "first default variable in the simple array: " << simple[0] << std::endl;
            // here we assigned 55 to array[0], how did we know which array it will change?
            // simply the array focused or affected is the array that we used in the operator[]
            simple[0] = 55;
            std::cout << "simple int array size: " << simple.size() << std::endl;
            // exception handle
            // std::cout << simple[200] << std::endl;
        }
        catch (std::out_of_range &n)
        {
            std::cout << n.what() << std::endl;
        }
    }
    {
        Array<std::string> strings(5);

        std::cout << "----------------------------------------------\n";
        strings[0] = "astro";
        strings[1] = "world";
        strings[2] = "is";
        strings[3] = "amazing";
        for (unsigned int i = 0; i < strings.size(); i++)
        {
            std::cout << strings[i] << " ";
        }
        std::cout << std::endl;
        // exception handle
        // std::cout << simple[200] << std::endl;
    }
    {
        std::cout << "----------------------------------------------\n";
        Array<double> numbers(4);

        numbers[0] = 42.3;
        numbers[1] = 1304;
        numbers[2] = 24.4;
        numbers[3] = 12;

        std::cout << "original array: ";
        for (unsigned int i = 0; i < numbers.size(); i++)
        {
            std::cout << numbers[i] << " ";
        }
        std::cout << std::endl;

        
        std::cout << "copied array: ";
        Array<double> copies(numbers);
        for (unsigned int i = 0; i < copies.size(); i++)
        {
            std::cout << copies[i] << " ";
        }
        std::cout << std::endl;

        copies[0] = 5555;
        copies[1] = 2;
        copies[2] = 4;
        copies[3] = 1;
        std::cout << "----------->\n";

        std::cout << "original array: ";
        for (unsigned int i = 0; i < numbers.size(); i++)
        {
            std::cout << numbers[i] << " ";
        }
        std::cout << std::endl;

        
        std::cout << "copied array: ";
        for (unsigned int i = 0; i < copies.size(); i++)
        {
            std::cout << copies[i] << " ";
        }
    }
}