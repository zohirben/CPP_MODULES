#pragma once

#include <string>
#include <iostream>

class Zombie
{
private:
    std::string name;

public:
    Zombie();
    Zombie(std::string name);
    ~Zombie();
    void announce(void);

    std::string getName() const;
    void    setName(const std::string &Name);
};

Zombie* newZombie(std::string name);
void randomChump( std::string name );