#include <iostream>

int main(int ac , char **av)
{
    if (ac < 2)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        int i = 1;
        int j = 0;
        while(av[i])
        {
            j = 0;
            while(av[i][j])
                std::cout << (char) toupper(av[i][j++]);
            i++;
        }
        std::cout << std::endl;
    }
}