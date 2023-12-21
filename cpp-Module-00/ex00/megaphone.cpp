#include <iostream>
#include <string>

void Capitalize(std::string& input)
{
    for (uint32_t i = 0; i < input.length(); i++)
    {
        input.at(i) = std::toupper(input.at(i));
    }
}

int main(int ac, char *av[])
{
    if (ac < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (1);
    }
    for (int i = 1; i < ac; i++)
    {
        std::string Temp = av[i];
        Capitalize(Temp);
        std::cout << Temp << " ";
    }
    std::cout << std::endl;
}