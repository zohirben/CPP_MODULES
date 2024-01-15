#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal constructor called" << std::endl;
    this->type = "Animal";
}

Animal::Animal(const Animal &copy)
{
    std::cout << "Animal Copy constructor called" << std::endl;
    this->type = copy.type;
}

Animal &Animal::operator=(const Animal &other)
{
    std::cout << "Animal Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->type = other.type;
    }
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal Destructor Has Been Called" << std::endl;
}

std::string Animal::getType() const
{
    return (this->type);
}

void Animal::makeSound() const
{
    std::cout << "****silence****" << std::endl;
}