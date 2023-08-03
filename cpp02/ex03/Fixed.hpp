#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

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

        // Constructor overload int
        Fixed(const int value);
        // Constructor overload float
        Fixed(const float value);
    
        // overload comparison operator
        bool operator>(const Fixed &rhs) const;
        bool operator<(const Fixed &rhs) const;
        bool operator>=(const Fixed &rhs) const;
        bool operator<=(const Fixed &rhs) const;
        bool operator==(const Fixed &rhs) const;
        bool operator!=(const Fixed &rhs) const;

        // overload arithmetic operator
        Fixed operator+(const Fixed &rhs) const;
        Fixed operator-(const Fixed &rhs) const;
        Fixed operator*(const Fixed &rhs) const;
        Fixed operator/(const Fixed &rhs) const;

        // overload increment and decrement operator
        Fixed &operator++(void);
        Fixed operator++(int);
        Fixed &operator--(void);
        Fixed operator--(int);

        // From ex01
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;

        // public overloaded member functions
        static Fixed &min(Fixed &a, Fixed &b);
        static const Fixed &min(const Fixed &a, const Fixed &b);
        static Fixed &max(Fixed &a, Fixed &b);
        static const Fixed &max(const Fixed &a, const Fixed &b);

};

// From ex01
std::ostream &operator<<(std::ostream &out, const Fixed &rhs);

#endif