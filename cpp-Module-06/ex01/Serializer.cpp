#include "Serializer.hpp"

Serializer::Serializer()
{
}
Serializer::Serializer(const Serializer &other)
{
    *this = other;
}
Serializer &Serializer::operator=(const Serializer &other)
{
    (void)other;
    return *this;
}
Serializer::~Serializer()
{
}

// It takes a pointer and converts it to the unsigned integer type uintptr_t.
uintptr_t Serializer::serialize(Data *ptr)
{
    uintptr_t uintptr;

    uintptr = reinterpret_cast<uintptr_t>(ptr);
    return (uintptr);
}

// It takes an unsigned integer parameter and converts it to a pointer to Data.
Data *Serializer::deserialize(uintptr_t raw)
{
    Data *ptr;

    ptr = reinterpret_cast<Data*>(raw);
    return (ptr);
}
