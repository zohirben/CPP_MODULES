#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal constructor called" << std::endl;
    this->type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
    std::cout << "WrongAnimal Copy constructor called" << std::endl;
    this->type = copy.type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
    std::cout << "WrongAnimal Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->type = other.type;
    }
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Destructor Has Been Called" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return (this->type);
}

void WrongAnimal::makeSound() const
{
    std::cout << "****silence****" << std::endl;
}