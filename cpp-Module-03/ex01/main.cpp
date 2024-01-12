#include "ScavTrap.hpp"

int main()
{
    ClapTrap Player1("Basem");
    ScavTrap Player2;
    Player1.attack(Player2.getName());
    Player2.takeDamage(Player1.getAttackDamage());

    Player2.beRepaired(3);
    std::cout << "ReVENGE TIME!\n" << std::endl;
    Player2.attack(Player1.getName());
}