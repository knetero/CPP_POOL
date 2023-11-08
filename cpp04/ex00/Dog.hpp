#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include <iomanip>
#include "Animal.hpp"


class Dog : public Animal{
   public:
        Dog();
        Dog(const Dog &other);
        Dog& operator=(const Dog &other);
        ~Dog();

        void   makeSound()const;

    
};


#endif