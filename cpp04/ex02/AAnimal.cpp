#include "AAnimal.hpp"

AAnimal::AAnimal(){
    std::cout << "AAnimal Default constructor called" << std::endl;
}
AAnimal::AAnimal(std::string Type){
    std::cout << "AAnimal constructor called" << std::endl;
    type = Type;
}

AAnimal::AAnimal(const AAnimal &other){
    std::cout << "AAnimal Copy constructor called" << std::endl;
    *this = other;
}

AAnimal& AAnimal::operator=(const AAnimal &other){
    std::cout << "AAnimal Copy assignment operator called" << std::endl;
    if (this != &other)
        this->type = other.type;
    return *this;
}

std::string AAnimal::getType() const{
    return type;
}

void AAnimal::makeSound() const{
    std::cout << "AAnimal sound" << std::endl;
}

AAnimal::~AAnimal(){
    std::cout << "AAnimal Destructor called" << std::endl;
}