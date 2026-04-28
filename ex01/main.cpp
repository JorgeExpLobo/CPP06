#include "Serializer.hpp"
#include <iostream>

int main() {
    Data data;
    data.x = 42;
    data.ref = "TESTING";
    Data* original = &data;
    uintptr_t raw = Serializer::serialize(original);

    Data* result = Serializer::deserialize(raw);

    std::cout << "Original memory address: " << original << std::endl;
    std::cout << "Serialized/Deserialized memory address: " << result << std::endl;


    std::cout << "Original x value: " << original->x << std::endl;
    std::cout << "Original ref value: " << original->ref << std::endl;
    std::cout << "Serialized/Deserialized x value: " << result->x << std::endl;
    std::cout << "Serialized/Deserialized ref value: " << result->ref << std::endl;
    if (result == original)
        std::cout << "Both pointers are equal" << std::endl;
    else std::cout << "Pointers are not equal" << std::endl;

    return 0;
}
