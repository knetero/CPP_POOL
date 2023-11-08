#include "AMateria.hpp"

AMateria::AMateria(){
    // std::cout << "AMateria Default constructor called" << std::endl;
}
AMateria::AMateria(std::string const & type){
    // std::cout << "AMateria constructor called" << std::endl;
    this->_type = type;
}

AMateria::~AMateria(){
    // std::cout << "AMateria Destructor called" << std::endl;
}


std::string const &AMateria::getType()const{
    return this->_type;
}
