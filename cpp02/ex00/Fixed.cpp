#include "Fixed.hpp"

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    this->fixedpoint_value = 0;
}

Fixed::Fixed( const Fixed &fixed ) {
    std::cout << "Copy constructor called" << std::endl;
    this->setRawBits(fixed.getRawBits());
}

Fixed& Fixed::operator=(const Fixed &obj){
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &obj)
        this->fixedpoint_value = obj.getRawBits();
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->fixedpoint_value;
}

void Fixed::setRawBits(int const raw){
    this->fixedpoint_value = raw;
}