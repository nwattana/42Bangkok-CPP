#include "Fixed.hpp"

// : affter function name is called member initializer list.
// It is used to initialize const member variable.
Fixed::Fixed(void) : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

// NEW overload constructor to accept int
Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    this->_value = value << this->_bits;
}

// NEW overload constructor to accept float
Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    this->_value = roundf(value * (1 << this->_bits));
}

Fixed::Fixed(const Fixed &src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_value = other.getRawBits();
    return *this;
}

// const เพื่อบอกว่า function เป็น const member function.
// const allow function to call on const object.
int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
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