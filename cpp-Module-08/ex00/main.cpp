#include "easyfind.hpp"
#include <list>
int main()
{
    std::list<int> containers;

    int x = 5;
    containers.push_back(3);
    containers.push_back(7);
    containers.push_back(3);
    containers.push_back(2);
    containers.push_back(1);
    // we cant access directly by using [] in list, instead we used iterator.
    // iterators are used to navigate through elements in a container they work like pointers and theres different types.
    std::list<int>::iterator it = containers.begin();
    // every iterator works based on the information provided by the container to know how to move from one element to the next.
    // ex: std::list the iterator moves using links between elements to move forward or backward, in std::vector the iterator
    // knows the fact that elemets are stored in a contiguous memory(one after one) so it simply moves by incrementing or decrementing a pointer.
    // thats why we used advance here, it knows how to increase the iterator whatever it is.
    std::advance(it, 3);
    containers.insert(it, 102);

    try {
        easyfind(containers, x);
    }
    catch(const std::runtime_error &c)
    {
        std::cerr << "exception: " << c.what() << '\n';
    }
    std::cout << "current containers: ";
    for (std::list<int>::iterator it = containers.begin(); it != containers.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return (0);
}