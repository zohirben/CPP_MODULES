#pragma once

#include <string>
#include <iostream>

class Animal 
{
protected:
    std::string type;
public:
    Animal();
    Animal(const Animal &copy);
    Animal &operator=(const Animal &other);
    virtual ~Animal();

    std::string getType() const;
    virtual void    makeSound() const;
};