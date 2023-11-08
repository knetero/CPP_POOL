#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>
#include <iomanip>


class AAnimal
{
    protected:
        std::string type;
    public:
        AAnimal();
        AAnimal(std::string Type);
        AAnimal(const AAnimal &other);
        AAnimal& operator=(const AAnimal &other);
        virtual ~AAnimal();

        std::string getType()const;
        virtual void makeSound()const = 0;

};


#endif