#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <iomanip>

typedef struct Data {
    int i;
} Data;

class Serializer {
    private:
        Serializer();
        Serializer(const Serializer& other);
        ~Serializer();

    public:
        Serializer& operator=(const Serializer& other);
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);

};

#endif
