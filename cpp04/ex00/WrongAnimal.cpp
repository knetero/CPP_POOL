#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
    type = "WrongAnimal";
    std::cout << "WrongAnimal Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other){
    std::cout << "WrongAnimal constructor called" << std::endl;
    *this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other){
    std::cout << "WrongAnimal Copy assignment operator called" << std::endl;
    if (this != &other)
        this->type = other.type;
    return *this;
}

std::string WrongAnimal::getType() const{
    return type;
}

void WrongAnimal::makeSound()const {
    std::cout << "WrongAnimal makeSound called" << std::endl;
} 

WrongAnimal::~WrongAnimal(){
    std::cout << "WrongAnimal Destructor" << std::endl;
}
