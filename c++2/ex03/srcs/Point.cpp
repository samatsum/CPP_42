/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 19:38:52 by samatsum          #+#    #+#             */
/*   Updated: 2025/05/06 21:50:08 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"
#include "../include/Point.hpp"

Point::Point() 
: _x(0)
, _y(0)
{
}

Point::Point(const float x, const float y) 
: _x(x), _y(y)
{
}

Point::Point(const Point& src) 
: _x(src._x), _y(src._y)
{
}

Point& Point::operator=(const Point& rhs)
{
    (void)rhs;
    return *this;
}

Point::~Point()
{
}

/* ************************************************************************** */
Fixed Point::get_X() const
{
    return (this->_x);
}

Fixed Point::get_Y() const
{
    return (this->_y);
}