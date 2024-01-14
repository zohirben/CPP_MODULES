#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    ClapTrap claptrap("Basem");
    claptrap.attack("Ghoul");

    std::cout << "\t\t" << std::endl;

    ScavTrap scavtrap("Ninja");
    scavtrap.attack("Slime");
    scavtrap.guardGate();

    std::cout << "\t\t" << std::endl;

    FragTrap fragtrap("Yasuo");
    fragtrap.attack("Fiddlestick");
    fragtrap.highFivesGuys();
    
    std::cout << "\t\t" << std::endl;

    return 0;
}