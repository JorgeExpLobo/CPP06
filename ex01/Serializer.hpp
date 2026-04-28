#pragma once
#include <cstdint>
#include "Data.hpp"

class Serializer {
    private:
        Serializer();
        ~Serializer();
        Serializer(const Serializer&);
		Serializer& operator=(const Serializer&);

    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};