#include "Zombie.hpp"

int main()
{
    Zombie *GroupOfRetards;
    const int size = 4;

    GroupOfRetards = zombieHorde(size, "NPC");
    for (int i = 0; i < size; i++)
    {
        GroupOfRetards[i].announce();
    }
    delete[] GroupOfRetards;
    GroupOfRetards = NULL;
}