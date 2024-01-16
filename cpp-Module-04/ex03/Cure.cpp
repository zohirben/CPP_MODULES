#include "Cure.hpp"

Cure::Cure() : AMateria("Cure")
{
    this->type = "Cure";
}

Cure::Cure(const Cure &copy) : AMateria(copy.type)
{}

Cure::~Cure()
{
}

AMateria *Cure::clone() const
{
    return new Cure(*this);
}

void Cure::use(ICharacter &target)
{
    std::cout << "* shoots an Cure bolt at" << ... << " *" << std::endl;
}