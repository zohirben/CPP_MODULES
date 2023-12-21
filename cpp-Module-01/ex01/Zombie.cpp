#include "Zombie.hpp"

Zombie::Zombie() : name("Default Zombie")
{
}
Zombie::~Zombie()
{
    std::cout << "The Desctructor Has Been Called! " << name << " Is Destroyed" << std::endl;
}

Zombie::Zombie(std::string name) : name(name)
{
}

void Zombie::announce(void)
{
    std::cout << getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string Zombie::getName() const 
{
    return name;
}

void    Zombie::setName(const std::string &Name)
{
    name = Name;
}
