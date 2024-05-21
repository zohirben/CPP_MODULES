#include "Base.hpp"

Base::~Base()
{
}

Base *generate(void)
{
    // sets the random function seed to different number based on current time
    std::srand(std::time(0));
    int random = 2;
    random = std::rand() % 3;
    switch (random)
    {
    case 0:
        return new A();
    case 1:
        return new B();
    case 2:
        return new C();
    }
    return NULL;
}

void identify(Base *p)
{
    if (dynamic_cast<A *>(p) != NULL)
        std::cout << "Object Pointed By p is A" << std::endl;
    else if (dynamic_cast<B *>(p) != NULL)
        std::cout << "Object Pointed By p is B" << std::endl;
    else if (dynamic_cast<C *>(p) != NULL)
        std::cout << "Object Pointed By p is C" << std::endl;
    else
        std::cout << "Unknown Type" << std::endl;
}

void identify(Base &p)
{
    try
    {
        // a is a reference to an A object so if the casting is succeeded it will print out the type of object.
        // else it will throw and exception 
        A &a = dynamic_cast<A&>(p);
        std::cout << "Object Refferenced By p is A" << std::endl;
        (void)a;
    }
    catch (std::bad_cast)
    {
    }
    try
    {
        B &b = dynamic_cast<B&>(p);
        std::cout << "Object Refferenced By p is B" << std::endl;
        (void)b;
    }
    catch (std::bad_cast)
    {
    }
    try
    {
        C &c = dynamic_cast<C&>(p);
        std::cout << "Object Refferenced By p is C" << std::endl;
        (void)c;
    }
    catch (std::bad_cast)
    {
    }
}