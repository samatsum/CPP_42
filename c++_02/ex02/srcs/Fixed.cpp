#include "../include/Fixed.hpp"

Fixed::Fixed() : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

// 10 → 10 * 256 = 2560
Fixed::Fixed(const int int_value)
{
    std::cout << "Int constructor called" << std::endl;
    this->_value = int_value << this->_fractional_bits;
}
// 42.42f * 256 = 10859.52 -> roundf(10859.52) = 10860
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

std::ostream& operator<<(std::ostream& output_stream, const Fixed& fixed)
{
    output_stream << fixed.toFloat();
    return output_stream;
}

bool	Fixed::operator>(Fixed fixed) const
{
	return (this->toFloat() > fixed.toFloat());
}

bool	Fixed::operator<(Fixed fixed) const
{
	return (this->toFloat() < fixed.toFloat());
}

bool	Fixed::operator>=(Fixed fixed) const
{
	return (this->toFloat() >= fixed.toFloat());
}

bool	Fixed::operator<=(Fixed fixed) const
{
	return (this->toFloat() <= fixed.toFloat());
}

bool	Fixed::operator==(Fixed fixed) const
{
	return (this->toFloat() == fixed.toFloat());
}

bool	Fixed::operator!=(Fixed fixed) const
{
	return (this->toFloat() != fixed.toFloat());
}

// Overloaded Arithmetic Operators
float	Fixed::operator+(Fixed fixed) const
{
	return (this->toFloat() + fixed.toFloat());
}

float	Fixed::operator-(Fixed fixed) const
{
	return (this->toFloat() - fixed.toFloat());
}

float	Fixed::operator*(Fixed fixed) const
{
	return (this->toFloat() * fixed.toFloat());
}

float	Fixed::operator/(Fixed fixed) const
{
	return (this->toFloat() / fixed.toFloat());
}

// Overloaded pre-increment Operators
Fixed	Fixed::operator++()
{
	this->_value++;
	return (*this);
}

Fixed	Fixed::operator--()
{
	this->_value--;
	return (*this);
}

// Overloaded post-increment Operators
Fixed	Fixed::operator++(int)
{
	Fixed tmp = *this;
	// i = this->_value;
	++this->_value;
	return (tmp);
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp = *this;
	// i = this->_value;
	--this->_value;
	return (tmp);
}

Fixed	&Fixed::min(Fixed &first, Fixed &second)
{
	if (first.toFloat() <= second.toFloat())
		return (first);
	else
		return (second);
}

const Fixed	&Fixed::min(const Fixed &first, const Fixed &second)
{
	if (first.toFloat() <= second.toFloat())
		return (first);
	else
		return (second);
}

Fixed	&Fixed::max(Fixed &first, Fixed &second)
{
	if (first.toFloat() >= second.toFloat())
		return (first);
	else
		return (second);
}

const Fixed	&Fixed::max(const Fixed &first, const Fixed &second)
{
	if (first.toFloat() >= second.toFloat())
		return (first);
	else
		return (second);
}
