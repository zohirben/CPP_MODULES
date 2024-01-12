#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "Default ClapTrap constructor called" << std::endl;
    this->Name = "Default ClapTrap";
    this->HitPoints = 10;
    this->EnergyPoints = 10;
    this->AttackDamage = 0;
}

ClapTrap::ClapTrap(const std::string &name)
{
    std::cout << "ClapTrap constructor called" << std::endl;
    this->Name = name;
    this->HitPoints = 10;
    this->EnergyPoints = 10;
    this->AttackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
    std::cout << "ClapTrap Copy constructor called" << std::endl;
    this->Name = copy.getName();
    this->HitPoints = copy.getEnergyPoints();
    this->EnergyPoints = copy.getEnergyPoints();
    this->AttackDamage = copy.getAttackDamage();
}
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "ClapTrap Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->Name = other.getName();
        this->HitPoints = other.getEnergyPoints();
        this->EnergyPoints = other.getEnergyPoints();
        this->AttackDamage = other.getAttackDamage();
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << this->Name << " ClapTrap Destructor Has Been Called" << std::endl;
}

std::string ClapTrap::getName() const
{
    return this->Name;
}

unsigned int ClapTrap::getHitPoints() const
{
    return this->HitPoints;
}

void ClapTrap::setHitPoints(int hitPoints)
{
    if (this->HitPoints <= 0)
        std::cout << "ClapTrap " << this->Name << "Is Already Dead" << std::endl;
    else
    {
        if (hitPoints <= 0)
            this->HitPoints = 0;
        else
            this->HitPoints = hitPoints;
        if (this->HitPoints <= 0)
            std::cout << "ClapTrap " << this->Name << " Is Dead!!!" << std::endl;
    }
}

unsigned int ClapTrap::getEnergyPoints() const
{
    return this->EnergyPoints;
}

void ClapTrap::setEnergyPoints(int energyPoints)
{
    if (this->EnergyPoints <= 0)
        this->EnergyPoints = 0;
    this->EnergyPoints = energyPoints;
}

unsigned int ClapTrap::getAttackDamage() const
{
    return this->AttackDamage;
}

void ClapTrap::setAttackDamage( int attackDamage)
{
    if (attackDamage < 0)
        this->AttackDamage = attackDamage * -1;
    this->AttackDamage = attackDamage;
}

void ClapTrap::attack(const std::string &target)
{
    if (this->EnergyPoints > 0)
    {
        this->setEnergyPoints(this->EnergyPoints-1);
        std::cout << "ClapTrap " << this->Name << " Attacks " << target << " causing " << getAttackDamage() << " points of damage!!" << std::endl;
    }
    else
        std::cout << "ClapTrap " << this->Name << " Can't Attack " << target << " due to insufficient energy points!" << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "ClapTrap " << this->Name << " Took " << amount << " Attack Damage!!!" << std::endl;
    this->setHitPoints(this->HitPoints - amount);
}
void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->EnergyPoints == 0)
    {
        std::cout << "ClapTrap " << this->Name << " Cannot repair itself due to insufficient energy points!" << std::endl;
        return;
    }
    else
    {
        this->setEnergyPoints(this->EnergyPoints-1);
        if (this->HitPoints > 0)
        {
            this->setHitPoints(this->HitPoints + amount);
            std::cout << "ClapTrap " << this->Name << " Repaired Itself And Gained " << amount << " Amount of Health :D" << std::endl;
        }
        else
            std::cout << "ClapTrap " << this->Name << " Cannot repair itself if its already dead" << std::endl;
    }
}