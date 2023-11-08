#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include <iostream>
#include <iomanip>
#include "WrongAnimal.hpp"


class WrongCat : public WrongAnimal{
    public:
        WrongCat();
        WrongCat(std::string type);
        ~WrongCat();

        WrongCat(const WrongCat&other);
        WrongCat& operator=(const WrongCat&other);

        void makeSound(void)const;
};

#endif