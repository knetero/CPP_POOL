#include "Fixed.hpp"

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    this->fixedpoint_value = 0;
}

Fixed::Fixed( const int n ) : fixedpoint_value(n << NUM_FRACTIONAL_BITS){
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float n ) : fixedpoint_value(std::roundf(n * (1 << NUM_FRACTIONAL_BITS))){
    std::cout << "Float constructor called" << std::endl;
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
    return this->fixedpoint_value;
}

void Fixed::setRawBits(int const raw){
    this->fixedpoint_value = raw;
}

float   Fixed::toFloat( void ) const {
    return (float)(this->getRawBits() ) / ( 1 << NUM_FRACTIONAL_BITS );
}

int     Fixed::toInt( void ) const {
    return this->fixedpoint_value >> NUM_FRACTIONAL_BITS;
}

std::ostream & operator<<( std::ostream &os, Fixed const &i ){
    os << i.toFloat();
    return os;
}
