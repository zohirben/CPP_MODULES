#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    {
        int N = 4;
        Animal *animals[N];
        for (int i = 0; i < N; i++)
        {
            if (i % 2 == 0)
                animals[i] = new Cat();
            else
                animals[i] = new Dog();
        }

        for (int i = 0; i < N; i++)
        {
            delete animals[i];
        }
        // we are freeing everything fine because of making the destructor of the base class virtual
        // because if we didnt it will cause the problem to call only the desctructor of the Base class only
    }
    // system("leaks animalv2");
    {
        std::cout << "---------------------------\n\n";
        const Animal *j = new Dog();
        const Animal *i = new Cat();
        delete j; // should not create a leak
        delete i;
    }
    // system("leaks animalv2");
}