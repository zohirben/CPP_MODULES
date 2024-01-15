#include "Brain.hpp"

Brain::Brain()
{
    for (int i = 0; i < 100; i++)
    {
        ideas[i] = "";
    }
}
Brain::Brain(const Brain &copy) {
    for (int i = 0; i < 100; i++) {
        this->ideas[i] = copy.ideas[i];
    }
}

Brain &Brain::operator=(const Brain &other) {
    if (this != &other) {
        for (int i = 0; i < 100; i++) {
            this->ideas[i] = other.ideas[i];
        }
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain Destructor Has Been Called" << std::endl;
}