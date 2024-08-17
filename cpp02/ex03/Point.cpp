/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 06:07:16 by muel-bak          #+#    #+#             */
/*   Updated: 2024/08/15 13:37:53 by muel-bak         ###   ########.fr       */
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

Fixed abs(Fixed x)
{
	return (x < 0) ? x * -1 : x;
}

Fixed signed_areas(Point a, Point b, Point c)
{
	return (a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY())) / 2.0f;
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed triangle_area = abs(signed_areas(a, b, c));
	Fixed area_1 = abs(signed_areas(point, a, b));
	Fixed area_2 = abs(signed_areas(point, b, c));
	Fixed area_3 = abs(signed_areas(point, c, a));

	// std::cout << area_1 << "  " << area_2 << "  " << area_3 << " == " << triangle_area << " == " << area_1 + area_2 + area_3 <<  std::endl;

	bool A = !(area_1 == Fixed(0) || area_2 == Fixed(0) || area_3 == Fixed(0));
	bool B = (area_1 + area_2 + area_3) == triangle_area;

	return (A && B);
}