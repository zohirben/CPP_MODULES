#pragma once

#include <string>
#include <iostream>

class WrongAnimal 
{
protected:
    std::string type;
public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal &copy);
    WrongAnimal &operator=(const WrongAnimal &other);
    virtual ~WrongAnimal();

    std::string getType() const;
    void    makeSound() const;
};