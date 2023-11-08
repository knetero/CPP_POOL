#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <iomanip>


class Fixed
{
    private:
        int fixedpoint_value;
        static const int NUM_FRACTIONAL_BITS = 8;
    public:
        Fixed();
        Fixed(const Fixed& fixed);
        Fixed& operator=(const Fixed &fixed);
        ~Fixed();
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
};

#endif