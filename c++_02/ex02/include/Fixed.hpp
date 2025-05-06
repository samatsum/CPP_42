
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
    int getRawBits( void ) const;
    void setRawBits( int const raw );
    float toFloat( void ) const;
    int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif