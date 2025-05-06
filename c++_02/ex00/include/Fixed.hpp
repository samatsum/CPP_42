/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum  <zunandkun@gmail.com      >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:04:35 by samatsum          #+#    #+#             */
/*   Updated: 2025/05/06 17:05:19 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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