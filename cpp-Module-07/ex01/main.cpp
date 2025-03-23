#include <iostream>
#include "iter.hpp"

int main()
{
    int array[10] = {13, 25 , 33 , 514 , 65 , 76 ,78 ,89 , 9 , 160};
    // why <int> after function pointer because when using function templates you need to specify the type you're using
    // so the compiler generates a version of the function that works with the type you want.
    iter(array, 10, print<int>);

    std::cout << std::endl;

    char string[] = "hello my fellow friend";
    // we can also use the regular functions too.
    iter(string, sizeof(string) - 1, to_upper);
    std::cout << string << '\n';

    double farray[5]  = {2.442 , 996.8 , 124.4, 9587611249.141248124857152, 0.0};
    // here we used a instantiated function template which is a special function version of a type that you want to deal different with
    iter(farray, 5, print<double>);
}