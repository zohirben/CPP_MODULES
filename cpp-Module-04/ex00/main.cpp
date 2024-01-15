#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    {
        const Animal *meta = new Animal();
        const Animal *j = new Dog();
        const Animal *i = new Cat();
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound(); // will output the cat sound!
        /* because of virtual keyword it will call the version of the method-
        based on the type of the object, not the
        type of the pointer or reference that is used to call the method.*/ 
        j->makeSound();
        meta->makeSound();

        delete meta;
        delete j;
        delete i;
    }
    {
        std::cout << "---------------------------" << std::endl;
        const WrongAnimal *meta = new WrongAnimal();
        const WrongAnimal *i = new WrongCat();

        std::cout << meta->getType() << " : ";
        meta->makeSound();
        std::cout << i->getType() << " : ";
        i->makeSound(); // will output the wrongAnimal sound!!

        std::cout << "\033[1;31mthe call of the method above is based on the type of the pointer or reference~" << std::endl;
        std::cout << "thats why its the same as the WrongAnimal Sound\033[0m" << std::endl;

        delete meta;
        delete i;
    }
    {
        std::cout << "---------------------------" << std::endl;
        const WrongAnimal *meta = new WrongAnimal();
        const WrongCat *i = new WrongCat();

        std::cout << meta->getType() << " : ";
        meta->makeSound();
        std::cout << i->getType() << " : ";
        i->makeSound();
        std::cout << "\033[1;32mthats why when we changed the pointer to the derived class object~" << std::endl;
        std::cout << "now it printed the actual method of the object\033[0m" << std::endl;

        delete meta;
        delete i;
    }
}