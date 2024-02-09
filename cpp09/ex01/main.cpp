#include "RPN.hpp"



int main(int ac, char **av) 
{
    if(ac < 2)
    {
        std::cerr << "Invalid argument" << std::endl;
        return 1;
    }
    std::string expr(av[1]);
    try {
        int result  = RPN(expr);
        std::cout <<  result << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
}