/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 06:07:16 by muel-bak          #+#    #+#             */
/*   Updated: 2024/07/05 06:18:39 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(float const x_value, float const y_value) : x(x_value), y(y_value) {}

Point::Point(Point const &other) : x(other.x), y(other.y) {}

Point &Point::operator=(Point const &other)
{
    if (this != &other)
    {
        const_cast<Fixed&>(this->x) = other.x;
        const_cast<Fixed&>(this->y) = other.y;
    }
    return *this;
}

Point::~Point() {}

Fixed Point::getX() const
{
    return x;
}

Fixed Point::getY() const
{
    return y;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed const zero(0);


    Fixed const v0_x = c.getX() - a.getX();
    Fixed const v0_y = c.getY() - a.getY();
    Fixed const v1_x = b.getX() - a.getX();
    Fixed const v1_y = b.getY() - a.getY();
    Fixed const v2_x = point.getX() - a.getX();
    Fixed const v2_y = point.getY() - a.getY();
    Fixed const dot00 = v0_x * v0_x + v0_y * v0_y;
    Fixed const dot01 = v0_x * v1_x + v0_y * v1_y;
    Fixed const dot02 = v0_x * v2_x + v0_y * v2_y;
    Fixed const dot11 = v1_x * v1_x + v1_y * v1_y;
    Fixed const dot12 = v1_x * v2_x + v1_y * v2_y;
    Fixed const invDenom = 1 / (dot00 * dot11 - dot01 * dot01);
    Fixed const u = (dot11 * dot02 - dot01 * dot12) * invDenom;
    Fixed const v = (dot00 * dot12 - dot01 * dot02) * invDenom;
    return ((u > zero) && (v > zero) && (u + v < Fixed(1)));
}

