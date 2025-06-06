/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:48:19 by samatsum          #+#    #+#             */
/*   Updated: 2025/05/06 19:02:02 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    std::cout << "setRawBits member function called" << std::endl;
    this->_value = raw;
}

float Fixed::toFloat() const
{
    return (static_cast<float>(this->_value) / (1 << _fractional_bits));
}

int Fixed::toInt() const
{
    return (this->_value >> _fractional_bits);
}

std::ostream& operator<<(std::ostream& output_stream, const Fixed& fixed)
{
    output_stream << fixed.toFloat();
    return (output_stream);
}