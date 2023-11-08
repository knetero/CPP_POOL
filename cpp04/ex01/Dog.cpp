#include "Dog.hpp"

Dog::Dog(){
    std::cout << "Dog Default constructor called" << std::endl;
    this->brain = new Brain();
    type = "Dog";
}

Dog::Dog(const Dog &other){
    *this = other;
	 this->brain = new Brain();
	*this->brain = *other.brain;
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog &other){
    std::cout << "Dog Copy assignment operator called" << std::endl;
    if (this != &other){
        this->type = other.type;
        this->brain = new Brain(*other.brain);
    }
    return *this;
}

void Dog::makeSound()const {
    std::cout << "Woof!" << std::endl;
} 

Dog::~Dog(){
    delete brain;
    std::cout << "Dog Destructor called" << std::endl;
}
