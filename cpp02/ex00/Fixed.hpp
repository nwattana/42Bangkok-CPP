#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        // an integer to store the fixed point value
        int _value;
        // the number of fractional bits always be 8
        static const int _bits = 8;

    public:
        // Default constructor
        Fixed(void);
        // Copy constructor
        Fixed(const Fixed &src);
        // Destructor
        ~Fixed(void);
        // Assignment operator overload
        Fixed &operator=(const Fixed &rhs);
    
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif