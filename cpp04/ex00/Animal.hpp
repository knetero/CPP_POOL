#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <iomanip>


class Animal
{
    protected:
        std::string type;
    public:
        Animal();
        Animal(std::string Type);
        Animal(const Animal &other);
        Animal& operator=(const Animal &other);
        virtual ~Animal();

        std::string getType() const;
        virtual void makeSound() const;

};


#endif