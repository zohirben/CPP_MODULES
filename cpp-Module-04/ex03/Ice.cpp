#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    this->type = "ice";
}

Ice::Ice(const Ice &copy) : AMateria(copy.type)
{}

Ice::~Ice()
{
}

AMateria *Ice::clone() const
{
    return new Ice(*this);
}

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at" << ... << " *" << std::endl;
}