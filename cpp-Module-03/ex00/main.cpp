#include "ClapTrap.hpp"

int main()
{
    ClapTrap Player1("Basem");
    ClapTrap Player2;
    Player1.setAttackDamage(-55);
    Player1.attack(Player2.getName());
    Player2.takeDamage(Player1.getAttackDamage());

    Player2.beRepaired(3);
}