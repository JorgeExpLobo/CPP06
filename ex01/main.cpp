#include "Serializer.hpp"
#include <iostream>

int main() {
    Data data;
    data.x = 42;
    data.ref = "TESTING";
    Data* original = &data;
    uintptr_t raw = Serializer::serialize(original);
    Data* result = Serializer::deserialize(raw);

    if (result == original)
        std::cout << "Both values are equal" << std::endl;
    else std::cout << "Values are not equal" << std::endl;

    return 0;
}
