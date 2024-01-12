#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "Default ScavTrap constructor called" << std::endl;
    this->Name = "Default ScavTrap";
    this->HitPoints = 100;
    this->EnergyPoints = 3;
    this->AttackDamage = 20;
}
ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
    std::cout << "ScavTrap constructor called" << std::endl;
    this->HitPoints = 100;
    this->EnergyPoints = 50;
    this->AttackDamage = 20;
}
ScavTrap::~ScavTrap()
{
    std::cout << this->Name << " ScavTrap Destructor Has Been Called" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->Name << " Is Now In Gate Keeper Mode" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    if (this->EnergyPoints > 0)
    {
        this->setEnergyPoints(this->EnergyPoints- 1);
        std::cout << "ScavTrap " << this->Name << " Attacks " << target << " with a powerful weapon dealing " << getAttackDamage() << " points of damage!!" << std::endl;
    }
    else
        std::cout << "ScavTrap " << this->Name << " Can't Attack " << target << "with its huge weapon due to insufficient energy points!" << std::endl;
}