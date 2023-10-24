#include "Harl.hpp"

int main(int ac, char **av)
{
    Harl harl;

    if(ac != 2)
        std::cout << "Please enter an argument!" << std::endl;
    else{
        std::string level = av[1];
        harl.complain(level);
    }
}