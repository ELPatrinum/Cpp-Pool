/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 06:05:21 by muel-bak          #+#    #+#             */
/*   Updated: 2024/07/05 06:09:02 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP
# include "Fixed.hpp"

class Point
{
private:
    Fixed const x;
    Fixed const y;

public:
    Point();
    Point(float const x_value, float const y_value);
    Point(Point const &other);
    Point &operator=(Point const &other);
    ~Point();

    Fixed getX() const;
    Fixed getY() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif