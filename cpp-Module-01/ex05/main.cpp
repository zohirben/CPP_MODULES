#include "Harl.hpp"

int main()
{
    Harl harl;
    std::string level;

    do
    {
        std::cout << "Enter a level (or 'quit' to exit): ";
        std::cin >> level;

        if (level != "quit")
        {
            harl.complain(level);
        }
        if (std::cin.eof())
        {
            std::cout << std::endl;
            exit(0);
        }
    }while (level != "quit");
}