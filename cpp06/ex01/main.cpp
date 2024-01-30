#include "Serializer.hpp"

int main()
{
    Data* data = new Data;
    data->i = 42;

    uintptr_t raw = Serializer::serialize(data);
    std::cout << "raw: " << raw << std::endl;

    Data* data2 = Serializer::deserialize(raw);
    std::cout << "data2->i: " << data2->i << std::endl;

    delete data;
}