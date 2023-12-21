#include "Harl.hpp"

int main(int ac, char **av)
{
    Harl harl;

    if (ac != 2)
    {
        std::cout << "Usage ./harlFilter 'DEBUG'/'INFO'/'WARNING'/'ERROR'" << std::endl;
        exit(1);
    }
    std::string level = av[1];
    harl.complain(level);
}