/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 01:16:22 by muel-bak          #+#    #+#             */
/*   Updated: 2024/07/05 06:15:43 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main()
{
    Point a(0.0f, 0.0f);
    Point b(2.0f, 0.0f);
    Point c(1.0f, 2.0f);

    Point p1(1.0f, 1.0f); // Inside
    Point p2(2.0f, 2.0f); // Outside
    Point p3(0.0f, 0.0f); // Vertex

    std::cout << "Point p1 is " << (bsp(a, b, c, p1) ? "inside" : "outside") << " the triangle." << std::endl;
    std::cout << "Point p2 is " << (bsp(a, b, c, p2) ? "inside" : "outside") << " the triangle." << std::endl;
    std::cout << "Point p3 is " << (bsp(a, b, c, p3) ? "inside" : "outside") << " the triangle." << std::endl;

    return 0;
}