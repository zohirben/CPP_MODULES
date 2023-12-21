#pragma once

#include "Weapon.hpp"

class HumanA
{
private:
    std::string name;
    Weapon &weapon;

public:
    HumanA(std::string name, Weapon &Weapon);
    void attack();

    std::string getName();
    std::string getWeapon();
};