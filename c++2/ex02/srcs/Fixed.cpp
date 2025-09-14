/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 17:13:58 by samatsum          #+#    #+#             */
/*   Updated: 2025/05/06 19:26:30 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

Fixed::Fixed() : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int int_value) : _value(int_value << _fractional_bits)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float float_value) : _value(roundf(float_value * (1 << _fractional_bits)))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
        this->_value = rhs.getRawBits();
    return (*this);
}

/* ************************************************************************** */
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

/* ************************************************************************** */
// rhs == "right-hand side"
bool Fixed::operator>(const Fixed& rhs) const
{
    return (this->_value > rhs._value);
}

bool Fixed::operator<(const Fixed& rhs) const
{
    return (this->_value < rhs._value);
}

bool Fixed::operator>=(const Fixed& rhs) const
{
    return (this->_value >= rhs._value);
}

bool Fixed::operator<=(const Fixed& rhs) const
{
    return (this->_value <= rhs._value);
}

bool Fixed::operator==(const Fixed& rhs) const
{
    return (this->_value == rhs._value);
}

bool Fixed::operator!=(const Fixed& rhs) const
{
    return (this->_value != rhs._value);
}

/* ************************************************************************** */
Fixed Fixed::operator+(const Fixed& rhs) const
{
    Fixed result;

    result.setRawBits(this->_value + rhs._value);
    return (result);
}

Fixed Fixed::operator-(const Fixed& rhs) const
{
    Fixed result;

    result.setRawBits(this->_value - rhs._value);
    return (result);
}

Fixed Fixed::operator*(const Fixed& rhs) const
{
    Fixed result;
    long long temp;
    
    temp = static_cast<long long>(this->_value) * static_cast<long long>(rhs._value);
    result.setRawBits(temp >> _fractional_bits);
    return (result);
}

Fixed Fixed::operator/(const Fixed& rhs) const
{    
    Fixed result;
    long long temp;
 
    temp = static_cast<long long>(this->_value) << _fractional_bits;
    result.setRawBits(temp / rhs._value);
    return (result);
}

/* ************************************************************************** */
Fixed& Fixed::operator++()
{
    this->_value += 1;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed old(*this);

    ++(*this);//Fixed& Fixed::operator++()
    return (old);
}

Fixed& Fixed::operator--()
{
    this->_value -= 1;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed old(*this);

    --(*this);//Fixed& Fixed::operator--()
    return (old);
}

/* ************************************************************************** */
Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    if (a < b)//bool Fixed::operator<(const Fixed& rhs) const
        return (a);
    return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a < b)//bool Fixed::operator<(const Fixed& rhs) const
        return (a);
    return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    if (a > b)//bool Fixed::operator>(const Fixed& rhs) const
        return (a);
    return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a > b)//bool Fixed::operator>(const Fixed& rhs) const
        return (a);
    return (b);
}