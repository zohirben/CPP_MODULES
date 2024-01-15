#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
    WrongCat();
    WrongCat(const WrongCat &copy);
    WrongCat &operator=(const WrongCat &other);
    ~WrongCat();

    void    makeSound(void) const;
};