
#ifndef FIXED_HPP
# define FIXED_HPP

#pragma once

#include <iostream>
#include <cmath>

class Fixed {
private:
    long long _value;
    static const int _fractional_bits = 8;
public:
    Fixed();
    Fixed(const int int_value);
    Fixed(const float float_value);
    Fixed(const Fixed& original);
    Fixed& operator=(const Fixed& original);
    ~Fixed();
    bool operator>(Fixed fixed)const;
    bool operator<(Fixed fixed)const;
    bool operator>=(Fixed fixed)const;
    bool operator<=(Fixed fixed)const;
    bool operator==(Fixed fixed)const;
    bool operator!=(Fixed fixed)const;
    float operator+(Fixed fixed)const;
    float operator-(Fixed fixed)const;
    float operator*(Fixed fixed)const;
    float operator/(Fixed fixed)const;
    Fixed operator++();
    Fixed operator--();
    Fixed operator++(int);
    Fixed operator--(int);
    int getRawBits( void ) const;
    void setRawBits( int const raw );
    float toFloat( void ) const;
    int toInt( void ) const;
    static Fixed &min(Fixed &first, Fixed &second);
    static const Fixed &min(Fixed const &first, Fixed const &second);
    static Fixed &max(Fixed &first, Fixed &second);
    static const Fixed &max(Fixed const &first, const Fixed &second);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif