/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:30:32 by muel-bak          #+#    #+#             */
/*   Updated: 2024/06/19 12:37:40 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
    Harl        harl;
	if (ac == 2)
	{
    	harl.Complain(av[1]);
    	return (0);
	}
	std::cout << "Harl_filter : Usage : ./Harl_filter [LEVEL] " << std::endl;
}
