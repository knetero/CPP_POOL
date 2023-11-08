#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){
    for (int i = 0; i < 4; i++){
        materia[i] = NULL;
    }
}

MateriaSource::~MateriaSource(){
    for (int i = 0; i < 4; i++)
        if (materia[i])
            delete materia[i];
}

MateriaSource::MateriaSource(MateriaSource const &other){
    *this = other;
}

MateriaSource& MateriaSource::operator=(MateriaSource const &other){
    if (this != &other){
        for (int i = 0; i < 4; i++)
            materia[i] = other.materia[i];
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria* m)
{
    for (int i = 0; i < 4; i++){
        if(materia[i] == NULL){
            materia[i] = m;
            return;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type){
    for (int i = 0; i < 4; i++)
    {
        if(materia[i] && materia[i]->getType() == type){
           return materia[i]->clone();
        }   
    }
    return 0;
}
