/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 19:38:42 by samatsum          #+#    #+#             */
/*   Updated: 2025/05/06 21:11:57 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

class Point {
private:
    Fixed const _x;
    Fixed const _y;

public:
    Point();
    Point(const float x, const float y);
    Point(const Point& src);
    ~Point();
    Point& operator=(const Point& rhs);

    // アクセサ
    Fixed get_X() const;
    Fixed get_Y() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif