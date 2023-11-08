#include "Cat.hpp"

Cat::Cat(){
    std::cout << "Cat Default constructor called" << std::endl;
    type = "Cat";
}

Cat::Cat(const Cat &other){
    std::cout << "Cat constructor called" << std::endl;
    *this = other;
}

Cat& Cat::operator=(const Cat &other){
    std::cout << "Cat Copy assignment operator called" << std::endl;
    if (this != &other)
        this->type = other.type;
    return *this;
}

void Cat::makeSound()const {
    std::cout << "Meow!" << std::endl;
} 

Cat::~Cat(){
    std::cout << "Cat Destructor called" << std::endl;
}
