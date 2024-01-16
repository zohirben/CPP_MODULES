#pragma once

#include "AMateria.hpp"

class Cure : public AMateria
{
    protected:
    public:
    Cure();
    Cure(const Cure &copy);
    ~Cure();

    std::string const &getType() const; // Returns the materia type
    AMateria *clone() const;
    void use(ICharacter &target);
}