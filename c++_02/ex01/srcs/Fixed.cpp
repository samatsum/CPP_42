#include "../include/Fixed.hpp"

Fixed::Fixed() : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int int_value)
{
    std::cout << "Int constructor called" << std::endl;
    this->_value = int_value << this->_fractional_bits;
}

Fixed::Fixed(const float float_value)
{
    std::cout << "Float constructor called" << std::endl;
    this->_value = roundf(float_value * (1 << _fractional_bits));
}

Fixed::Fixed(const Fixed& original)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = original;
}

Fixed& Fixed::operator=(const Fixed& original)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &original)
        this->_value = original.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

//////////////////////////////////////////////////////////////////
int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_value;
}

void Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}

float	Fixed::toFloat(void)const
{
	return ((float)this->_value / (float)(1 << this->_fractional_bits));
}

int	Fixed::toInt(void)const
{
	return (this->_value >> this->_fractional_bits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}
