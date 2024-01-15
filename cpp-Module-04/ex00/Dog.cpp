#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog constructor called" << std::endl;
    
    this->type = "Dog";
}

Dog::Dog(const Dog &copy)
{
    std::cout << "Dog Copy constructor called" << std::endl;
    this->type = copy.type;
}

Dog &Dog::operator=(const Dog &other)
{
    std::cout << "Dog Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->type = other.type;
    }
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog Destructor Has Been Called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "woof, woof, woof, woof, woof!" << std::endl;
}