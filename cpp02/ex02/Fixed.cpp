#include "Fixed.hpp"

Fixed::Fixed() {
    this->fixedpoint_value = 0;
}

Fixed::Fixed( const int n ) : fixedpoint_value(n << NUM_FRACTIONAL_BITS){
}

Fixed::Fixed( const float n ) : fixedpoint_value(std::roundf(n * (1 << NUM_FRACTIONAL_BITS))){
}

Fixed::Fixed( const Fixed &fixed ) {

    this->setRawBits(fixed.getRawBits());
}

Fixed& Fixed::operator=(const Fixed &obj){
    if (this != &obj)
        this->fixedpoint_value = obj.getRawBits();
    return *this;
}

Fixed::~Fixed(){
}

int Fixed::getRawBits(void) const{
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

std::ostream & operator<<( std::ostream &os, Fixed const &i ) {
    os << i.toFloat();
    return os;
}

bool Fixed::operator>(const Fixed &other) const{
    return this->getRawBits() > other.getRawBits();
}

bool Fixed::operator<(const Fixed &other) const{
    return this->getRawBits() < other.getRawBits();
}

bool Fixed::operator>=(const Fixed &other) const{
    return this->getRawBits() >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed &other) const{
    return this->getRawBits() <= other.getRawBits();
}

bool Fixed::operator==(const Fixed &other) const{
    return this->getRawBits() == other.getRawBits();
}

bool Fixed::operator!=(const Fixed &other) const{
    return this->getRawBits() != other.getRawBits();
}

Fixed   Fixed::operator+(const Fixed &other) const {
    return Fixed( this->toFloat() + other.toFloat());
}

Fixed   Fixed::operator-(const Fixed &other) const {
    return Fixed( this->toFloat() - other.toFloat());
}

Fixed   Fixed::operator*(const Fixed &other) const {
    return Fixed( this->toFloat() * other.toFloat());
}

Fixed   Fixed::operator/(const Fixed &other) const {
    return Fixed( this->toFloat() / other.toFloat());
}

Fixed& Fixed::min(Fixed& a, Fixed& b){
    if(a.getRawBits() > b.getRawBits())
        return b;
    return a;
}

Fixed& Fixed::max(Fixed& a, Fixed& b){
    if(a.getRawBits() > b.getRawBits())
        return a;
    return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b){
    if(a.getRawBits() > b.getRawBits())
        return b;
    return a;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b){
    if(a.getRawBits() > b.getRawBits())
        return a;
    return b;
}

Fixed& Fixed:: operator++(){
    ++this->fixedpoint_value;
    return *this;
}

Fixed& Fixed:: operator--(){
    --this->fixedpoint_value;
    return *this;
}

Fixed Fixed:: operator++(int){
    Fixed tmp(*this);
    tmp.fixedpoint_value = this->fixedpoint_value++;
    return tmp;
}

Fixed Fixed:: operator--(int){
    Fixed tmp(*this);
    tmp.fixedpoint_value = this->fixedpoint_value--;
    return tmp;
}



