#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include <iostream>
#include <iomanip>
#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "ICharacter.hpp"



class MateriaSource : public IMateriaSource
{
    private:
        AMateria* materia[4];
    public:
        MateriaSource();
        MateriaSource(const MateriaSource &other);
        MateriaSource& operator=(const MateriaSource &other);
    
        void learnMateria(AMateria* m);
        AMateria* createMateria(std::string const & type);

        virtual ~MateriaSource();

};


#endif