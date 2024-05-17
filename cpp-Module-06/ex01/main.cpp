#include "Serializer.hpp"

int main ()
{
    Data data;
    data.id = 33;
    data.name = "robot";

    // reinterpret_cast can convert any type to any other type.

    std::cout << "id = " << data.id << std::endl;
    std::cout << "name = " << data.name << std::endl;
    uintptr_t uniptr = Serializer::serialize(&data);
    std::cout << "Data serialized pointer = " << uniptr << std::endl;
    Data *dataptr = Serializer::deserialize(uniptr);

    std::cout << "Data Deserialized Pointer = " << dataptr << std::endl; 
    std::cout << "data Original Pointer = " << &data << std::endl;

    // the binary representation stays the same, the only difference is how it is displayed.
}