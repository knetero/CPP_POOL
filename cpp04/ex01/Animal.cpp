#include "Animal.hpp"

Animal::Animal(){
    std::cout << "Animal Default constructor called" << std::endl;
}
Animal::Animal(std::string Type){
    std::cout << "Animal constructor called" << std::endl;
    type = Type;
}

Animal::Animal(const Animal &other){
    std::cout << "Animal Copy constructor called" << std::endl;
    *this = other;
}

Animal& Animal::operator=(const Animal &other){
    std::cout << "Animal Copy assignment operator called" << std::endl;
    if (this != &other)
        this->type = other.type;
    return *this;
}

std::string Animal::getType() const{
    return type;
}

void Animal::makeSound() const{
    std::cout << "Animal sound" << std::endl;
}

Animal::~Animal(){
    std::cout << "Animal Destructor called" << std::endl;
}