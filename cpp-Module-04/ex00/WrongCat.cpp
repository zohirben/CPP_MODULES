#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout << "WrongCat constructor called" << std::endl;
    
    this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &copy)
{
    std::cout << "WrongCat Copy constructor called" << std::endl;
    this->type = copy.type;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
    std::cout << "WrongCat Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->type = other.type;
    }
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat Destructor Has Been Called" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "UwU? meow meow meow meow~~" << std::endl;
}