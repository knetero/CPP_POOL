#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include <iomanip>
#include "AAnimal.hpp"
#include "Brain.hpp"


class Cat : public AAnimal{
    private:
        Brain* brain;
    public:
        Cat();
        Cat(std::string name);
        Cat(const Cat &other);
        Cat& operator=(const Cat &other);
        ~Cat();

        void   makeSound()const;
};


#endif