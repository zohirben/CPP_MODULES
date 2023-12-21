#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &Weapon) : name(name), weapon(Weapon)
{
}

void HumanA::attack()
{
    std::cout << getName() << " attacks with their " << getWeapon() << std::endl;
}

std::string HumanA::getName()
{
    return name;
}
std::string HumanA::getWeapon()
{
    return weapon.getType();
}