#include "Iter.hpp"

template <typename T>
void    display_arr(const T& value)
{
    std::cout << value << std::endl;
}


int main( void ) 
{
    int tab[] = { 0, 1, 2, 3, 4 };
    ::iter(tab, 5, display_arr<const int>);

    std::string tab2[] = { "Hello", "World"};
    ::iter(tab2, 2, display_arr<const std::string>);

    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    ::iter(doubleArray, 5, display_arr<const double>);
}