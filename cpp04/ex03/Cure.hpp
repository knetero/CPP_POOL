#ifndef CURE_HPP
# define CURE_HPP

#include <iostream>
#include <iomanip>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class ICharacter;


class Cure : public AMateria
{
    public:
        Cure();
        Cure(std::string const &type);
        Cure(const Cure &other);
        Cure& operator=(const Cure &other);

        virtual AMateria* clone() const;
        virtual void use(ICharacter& target);
        ~Cure();
};


#endif