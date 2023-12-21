#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(NULL)
{
}

void HumanB::attack()
{
    std::cout << getName() << " attacks with their " << getWeapon() << std::endl;
}

std::string HumanB::getName()
{
    return name;
}
std::string HumanB::getWeapon()
{
    if (weapon)
        return weapon->getType();
    else
        return "Bare Hands";
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}