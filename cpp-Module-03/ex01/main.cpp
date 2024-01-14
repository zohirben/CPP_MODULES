#include "ScavTrap.hpp"

int main()
{
    ScavTrap Player2("Ninja");
    ClapTrap Player1("Basem");
    Player1.attack(Player2.getName());
    Player2.takeDamage(Player1.getAttackDamage());

    Player2.beRepaired(3);
    std::cout << "---ReVENGE TIME!---" << std::endl;
    Player2.attack(Player1.getName());
}