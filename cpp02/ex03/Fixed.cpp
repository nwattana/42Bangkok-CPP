#include "Fixed.hpp"

// : affter function name is called member initializer list.
// It is used to initialize const member variable.
Fixed::Fixed(void) : _value(0)
{
}

// NEW overload constructor to accept int
Fixed::Fixed(const int value)
{
    this->_value = value << this->_bits;
}

// NEW overload constructor to accept float
Fixed::Fixed(const float value)
{
    this->_value = roundf(value * (1 << this->_bits));
}

Fixed::Fixed(const Fixed &src)
{
    *this = src;
}

Fixed::~Fixed(void)
{
}

Fixed &Fixed::operator=(const Fixed &other)
{
    if (this != &other)
        this->_value = other.getRawBits();
    return *this;
}

// const เพื่อบอกว่า function เป็น const member function.
// const allow function to call on const object.
int Fixed::getRawBits(void) const
{
    return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}

float Fixed::toFloat(void) const
{
    return ((float)this->_value / (float)(1 << this->_bits));
}

int Fixed::toInt(void) const
{
    return (this->_value >> this->_bits);
}

std::ostream & operator<<( std::ostream & o, Fixed const & i ) {
    o << i.toFloat();
    return o;
}

// overload comparison operator

bool Fixed::operator>(const Fixed &rhs) const
{
    return (this->_value > rhs.getRawBits());
}

bool Fixed::operator<(const Fixed &rhs) const
{
    return (this->_value < rhs.getRawBits());
}

bool Fixed::operator>=(const Fixed &rhs) const
{
    return (this->_value >= rhs.getRawBits());
}

bool Fixed::operator<=(const Fixed &rhs) const
{
    return (this->_value <= rhs.getRawBits());
}

bool Fixed::operator==(const Fixed &rhs) const
{
    return (this->_value == rhs.getRawBits());
}

bool Fixed::operator!=(const Fixed &rhs) const
{
    return (this->_value != rhs.getRawBits());
}

// overload arithmetic operator
Fixed Fixed::operator+(const Fixed &rhs) const
{
    return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed Fixed::operator-(const Fixed &rhs) const
{
    return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed Fixed::operator*(const Fixed &rhs) const
{
    return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed Fixed::operator/(const Fixed &rhs) const
{
    return (Fixed(this->toFloat() / rhs.toFloat()));
}

// overload increment and decrement operator
Fixed &Fixed::operator++(void)
{
    this->_value++;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    operator++();
    return (tmp);
}

Fixed &Fixed::operator--(void)
{
    this->_value--;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    operator--();
    return (tmp);
}

// public overloaded member functions
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b ? a : b);
}