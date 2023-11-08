#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <iomanip>
#include <cmath>


class Fixed
{
    private:
        int fixedpoint_value;
        static const int NUM_FRACTIONAL_BITS = 8;
    public:
        Fixed();
        Fixed( const int n );
        Fixed( const float n );
        Fixed(const Fixed& fixed);
        Fixed& operator=(const Fixed &fixed);
        ~Fixed();

        int     getRawBits(void) const;
        void    setRawBits(int const raw);

        float   toFloat(void) const;
        int     toInt(void) const;


        bool operator>(const Fixed &other)const;
        bool operator<(const Fixed &other)const;
        bool operator>=(const Fixed &other)const;
        bool operator<=(const Fixed &other)const;
        bool operator==(const Fixed &other)const;
        bool operator!=(const Fixed &other)const;

        Fixed operator+( const Fixed &other )const;
        Fixed operator-( const Fixed &other ) const;
        Fixed operator*( const Fixed &other ) const;
        Fixed operator/( const Fixed &other ) const;

        Fixed& operator++();
        Fixed& operator--();
        Fixed operator++(int);
        Fixed operator--(int);

        static Fixed& min(Fixed& a, Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream & operator<<( std::ostream &os, Fixed const &i );

#endif