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
};

std::ostream & operator<<( std::ostream &os, Fixed const &i );

#endif