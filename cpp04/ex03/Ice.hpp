#ifndef ICE_HPP
# define ICE_HPP

#include <iostream>
#include <iomanip>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class ICharacter;

class Ice : public AMateria
{
    public:
        Ice();
        Ice(std::string const &type);
        Ice(const Ice &other);
        Ice& operator=(const Ice &other);

        virtual AMateria* clone() const;
        virtual void use(ICharacter& target);
        ~Ice();
};


#endif