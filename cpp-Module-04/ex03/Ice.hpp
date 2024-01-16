#pragma once

#include "AMateria.hpp"

class Ice : public AMateria
{
    protected:
    public:
    Ice();
    Ice(const Ice &copy);
    ~Ice();

    std::string const &getType() const; // Returns the materia type
    AMateria *clone() const;
    void use(ICharacter &target);
}