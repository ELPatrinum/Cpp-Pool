/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 06:07:16 by muel-bak          #+#    #+#             */
/*   Updated: 2024/07/24 11:25:41 by muel-bak         ###   ########.fr       */
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

// bool bsp(Point const a, Point const b, Point const c, Point const point)
// {
//     Fixed const zero(0);


//     Fixed const v0_x = c.getX() - a.getX();
//     Fixed const v0_y = c.getY() - a.getY();
//     Fixed const v1_x = b.getX() - a.getX();
//     Fixed const v1_y = b.getY() - a.getY();
//     Fixed const v2_x = point.getX() - a.getX();
//     Fixed const v2_y = point.getY() - a.getY();
//     Fixed const dot00 = v0_x * v0_x + v0_y * v0_y;
//     Fixed const dot01 = v0_x * v1_x + v0_y * v1_y;
//     Fixed const dot02 = v0_x * v2_x + v0_y * v2_y;
//     Fixed const dot11 = v1_x * v1_x + v1_y * v1_y;
//     Fixed const dot12 = v1_x * v2_x + v1_y * v2_y;
//     Fixed const invDenom = 1 / (dot00 * dot11 - dot01 * dot01);
//     Fixed const u = (dot11 * dot02 - dot01 * dot12) * invDenom;
//     Fixed const v = (dot00 * dot12 - dot01 * dot02) * invDenom;
//     return ((u > zero) && (v > zero) && (u + v < Fixed(1)));
// }

//==============================================================================================================================

// The sign of areas technique 
// is a method involves calculating the signed areas of triangles 
// formed by the point in question and the vertices of the original triangle.

// Given a triangle with vertices a(x1,y1), b(x2,y2), and c(x3,y3), 
// and a point point(px,py), the signed area of a triangle 
// formed by any three points (x1,y1), (x2,y2), and (px,py) 
// can be computed as:
// Area = 1/2 [(x1⋅(y2−py)+x2⋅(py−y1)+px⋅(y1−y2))]

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