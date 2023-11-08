#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

#include <iostream>
#include <iomanip>
#include "AMateria.hpp"
#include "ICharacter.hpp"


class IMateriaSource
{
    public:
        IMateriaSource();
        virtual ~IMateriaSource();
        virtual void learnMateria(AMateria*) = 0;
        virtual AMateria* createMateria(std::string const & type) = 0;
};


#endif