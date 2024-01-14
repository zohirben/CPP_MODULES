#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "Default FragTrap constructor called" << std::endl;
    this->Name = "Default FragTrap";
    this->HitPoints = 100;
    this->EnergyPoints = 100;
    this->AttackDamage = 30;
}
FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
    std::cout << "FragTrap name constructor called" << std::endl;
    this->HitPoints = 100;
    this->EnergyPoints = 100;
    this->AttackDamage = 30;
}
FragTrap::~FragTrap()
{
    std::cout << this->Name << " FragTrap Destructor Has Been Called" << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << this->Name << " Is up for a high five, who wants to join?" << std::endl;
}