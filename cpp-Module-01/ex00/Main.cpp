#include "Zombie.hpp"

int main()
{
    {
        Zombie zombie("Nigga");

    zombie.announce();
    }

    Zombie *Foo;
    Foo = newZombie("Fool");
    Foo->announce();
    delete Foo;
    randomChump("your mom");
}