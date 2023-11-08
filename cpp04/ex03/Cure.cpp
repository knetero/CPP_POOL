#include "Cure.hpp"

Cure::Cure() : AMateria("cure"){
    // std::cout << "Cure Default constructor called" << std::endl;
}

Cure::Cure(std::string const &type){
    // std::cout << "Cure constructor called" << std::endl;
    this->_type = type;
}

Cure::Cure(const Cure &other){
    // std::cout << "Cure Copy constructor called" << std::endl;
    *this = other;
}

Cure& Cure::operator=(const Cure &other){
    // std::cout << "Cure Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_type = other._type;
    return *this;
}

AMateria* Cure::clone()const{
    return new Cure();
}

void Cure::use(ICharacter& target){
    std::string name = target.getName();
    std::cout << "* heals " << name << "'s wounds *" << std::endl;
}

Cure::~Cure(){
    // std::cout << "Cure Destructor called" << std::endl;
}
