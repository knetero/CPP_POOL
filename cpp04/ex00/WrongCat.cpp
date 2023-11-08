#include "WrongCat.hpp"

WrongCat::WrongCat(){
    type = "WrongCat";
    std::cout << "WrongCat Default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other){
    std::cout << "WrongCat copy constructor called" << std::endl;
    *this = other;
}

WrongCat& WrongCat::operator=(const WrongCat &other){
    std::cout << "WrongCat Copy assignment operator called" << std::endl;
    if (this != &other)
        this->type = other.type;
    return *this;
}

void WrongCat::makeSound()const {
    std::cout << "Meow!" << std::endl;
} 

WrongCat::~WrongCat(){
    std::cout << "WrongCat Destructor" << std::endl;
}
