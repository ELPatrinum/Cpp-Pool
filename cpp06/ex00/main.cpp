/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:16:43 by muel-bak          #+#    #+#             */
/*   Updated: 2024/10/17 16:33:38 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main (int ac, char **av)
{
	if (ac != 2)
		return(1);
	if(!av[1])
		return(1);
	std::string str = av[1];
	ScalarConverter::convert(str);
	return (0);
}