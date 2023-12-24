#include "Zombie.hpp"

int main()
{
    {
        Zombie zombie("Richard");

        zombie.announce();
    }

    Zombie *Foo;
    Foo = newZombie("Fool");
    Foo->announce();
    delete Foo;
    randomChump("Zues");
}