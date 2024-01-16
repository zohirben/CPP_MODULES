#include "Character.hpp"

Character::Character()
{
    for (int i = 0; i < 4; i++)
    {
        this->Materias[i] = nullptr;
    }
}

Character::~Character()
{
    delete[] Materias;
}

std::string const &Character::getName() const
{
    
}

void Character::equip(AMateria *m)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->Materias[i] == nullptr)
        {
            this->Materias[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4)
        return;
    else
        this->Materias[idx] = nullptr;
}

void Character::use(int idx, ICharacter &target)
{
}
