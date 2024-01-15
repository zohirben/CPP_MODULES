#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    const Animal *j = new Dog();
    const Animal *i = new Cat();
    delete j; // should not create a leak
    delete i;
    // CANT DO: 
    // Animal monkey;
    // error: variable type 'Animal' is an abstract class
    // we cant declare a default animal class
}