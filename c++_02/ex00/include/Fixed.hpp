
#ifndef FIXED_HPP
# define FIXED_HPP

#pragma once

#include <iostream>

class Fixed {
private:
    long long _value;
    static const int _fractionalBits = 8;
public:
    Fixed();
    Fixed(const Fixed& original);
    Fixed& operator=(const Fixed& original);
    ~Fixed();
    int getRawBits( void ) const;
    void setRawBits( int const raw );
};

#endif