#pragma once

#include "Weapon.hpp"

class HumanB
{
private:
    std::string name;
    Weapon *weapon;

public:
    HumanB(std::string name);
    void attack();

    std::string getName();
    std::string getWeapon();
    void setWeapon(Weapon &weapon);
};