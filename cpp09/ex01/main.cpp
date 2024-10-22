/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:15:37 by muel-bak          #+#    #+#             */
/*   Updated: 2024/10/22 00:17:40 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2 || !av[1])
		return (std::cerr << "Usage : ./RPN [line] " << std::endl, 1);
	std::string line(av[1]);
	try
	{
		RPN rpn;
		rpn.calculate(line);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}