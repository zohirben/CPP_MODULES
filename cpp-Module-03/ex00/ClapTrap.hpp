#pragma once

#include <iostream>

class ClapTrap
{
private:
    std::string Name;
    int HitPoints;
    int EnergyPoints;
    int AttackDamage;

public:
    ClapTrap();
    ClapTrap(const std::string &name);
    ClapTrap(const ClapTrap &copy);
    ClapTrap &operator=(const ClapTrap &other);
    ~ClapTrap();

    //setters and getters
    std::string getName() const;

    unsigned int getHitPoints() const;
    void setHitPoints(int hitPoints);

    unsigned int getEnergyPoints() const;
    void setEnergyPoints(int energyPoints);

    unsigned int getAttackDamage() const;
    void setAttackDamage(int attackDamage);

    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};