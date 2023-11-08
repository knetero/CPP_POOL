#include "Dog.hpp"

Dog::Dog(){
    std::cout << "Dog Default constructor called" << std::endl;
    type = "Dog";
}

Dog::Dog(const Dog &other){
    std::cout << "Dog constructor called" << std::endl;
    *this = other;
}

Dog& Dog::operator=(const Dog &other){
    std::cout << "Dog Copy assignment operator called" << std::endl;
    if (this != &other)
        this->type = other.type;
    return *this;
}

void Dog::makeSound()const {
    std::cout << "Woof!" << std::endl;
} 

Dog::~Dog(){
    std::cout << "Dog Destructor called" << std::endl;
}
