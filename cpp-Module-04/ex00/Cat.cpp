#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat constructor called" << std::endl;
    
    this->type = "Cat";
}

Cat::Cat(const Cat &copy)
{
    std::cout << "Cat Copy constructor called" << std::endl;
    this->type = copy.type;
}

Cat &Cat::operator=(const Cat &other)
{
    std::cout << "Cat Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->type = other.type;
    }
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat Destructor Has Been Called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "UwU? meow meow meow meow~~" << std::endl;
}