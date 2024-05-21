#include "template.hpp"
#include <iostream>

int main()
{
    int a = 5;
    int b = 10;
    swap(a, b);

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;

    std::cout << "smallest data type is: " << min(a, b) << std::endl;
    std::cout << "biggest data type is: " << max(a, b) << std::endl;
}
