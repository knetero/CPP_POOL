#include "PmergeMe.hpp"
#include <cstddef>



int main(int ac, char **av)
{
    if(ac < 2)
    {
        std::cerr << "Invalid argumenets" << std::endl;
        return 1;
    }
    try{
        PmergeMe P(av);
    }
    catch(const std::exception &e)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

}