#pragma once

#include <iostream>
#include <stack>
#include <vector>
#include <list>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
    MutantStack(){};
    MutantStack(const MutantStack &other){this->c = other.c;};
    MutantStack &operator=(const MutantStack &other){
        if (this != &other)
            this->c = other.c;
        return *this;
    };
    ~MutantStack(){};

    // iterator variable here is a type alias for the iterator types of the underlying container of std::stack
    // with std::stack<T>::container_type here we asked for a type alias provided by std::stack that refers
    // to the type of container std::stack<T> uses so we can get the iterator type of that container
    // so we are using the iterator of that underlying vector/deque that std::stack uses.
    // std::stack already defined the iterator for its underlying container and it gives it when using container_type.
    typedef typename std::stack<T>::container_type::iterator iterator;

    // we recreated begin() and end() to be able to access the underlying container of std::stack outside of the function
    // because by default its std::stack's container so they are private outside this subclass.
    iterator begin()
    {
        return this->c.begin();
    }
    iterator end()
    {
        return this->c.end();
    }

};

