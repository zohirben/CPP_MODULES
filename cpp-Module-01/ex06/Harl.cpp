#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl()
{
    std::cout << "The Desctructor Has Been Called! " << std::endl;
}

void Harl::debug(void)
{
    std::cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
    std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
    std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now." << std::endl;
}
void Harl::complain(std::string level)
{
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    int index = -1;
    for (int i = 0; i < 4; i++)
    {
        if (level.compare(levels[i]) == 0)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        exit(1);
    }

    switch (index)
    {
    case 0:
        debug();
    case 1:
        info();
    case 2:
        warning();
    case 3:
        error();
    }
    exit(0);
}