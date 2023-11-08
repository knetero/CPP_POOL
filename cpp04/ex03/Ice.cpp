#include "Ice.hpp"

Ice::Ice() : AMateria("ice"){
    // std::cout << "Ice Default constructor called" << std::endl;
}

Ice::Ice(std::string const &type){
    // std::cout << "Ice constructor called" << std::endl;
    this->_type = type;
}

Ice::Ice(const Ice &other){
    // std::cout << "Ice Copy constructor called" << std::endl;
    *this = other;
}

Ice& Ice::operator=(const Ice &other){
    // std::cout << "Ice Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_type = other._type;
    return *this;
}

AMateria* Ice::clone()const{
    return new Ice();
}

void Ice::use(ICharacter& target){
    std::string name = target.getName();
    std::cout << "* shoots an ice bolt at " << name << " *" << std::endl;
}

Ice::~Ice(){
    // std::cout << "Ice Destructor called" << std::endl;
}
