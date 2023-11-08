#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <iomanip>

class WrongAnimal
{
    protected:
        std::string type;

    public:
        WrongAnimal();
        WrongAnimal(std::string type);
        ~WrongAnimal();

        WrongAnimal(const WrongAnimal&other);
        WrongAnimal& operator=(const WrongAnimal&other);

        void            makeSound() const;
        std::string     getType() const; 
};

#endif