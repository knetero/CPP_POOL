#include <iostream>

int main(int ac , char **av)
{
    std::string str;

    if (ac < 2)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        int i = 1;
        int j;
        while(i < ac)
        {
            str = av[i];
            j = 0;
            while(str[j])
                std::cout << (char) toupper(str[j++]);
            i++;
        }
        std::cout << std::endl;
    }
}