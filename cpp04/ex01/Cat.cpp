#include "Cat.hpp"

Cat::Cat(){
    std::cout << "Cat Default constructor called" << std::endl;
    this->brain = new Brain();
    type = "Cat";
}

Cat::Cat(const Cat &other){
    *this = other;
	this->brain = new Brain();
	*this->brain = *other.brain;
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat &other){
    std::cout << "Cat Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->type = other.type;
        this->brain = new Brain(*other.brain);
    }
    return *this;
}

void Cat::makeSound()const {
    std::cout << "Meow!" << std::endl;
} 

Cat::~Cat(){
    delete brain;
    std::cout << "Cat Destructor called" << std::endl;
}
