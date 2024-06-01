/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 04:31:48 by muel-bak          #+#    #+#             */
/*   Updated: 2024/06/01 05:06:49 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>


int main(int ac, char **av)
{
	int	i;
	int	j = 1;
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return(0);
	}
	while(j < ac)
	{
		i = 0;
		while(av[j][i])
		{
			if (av[j][i] >= 'a' && av[j][i] <= 'z')
				std::cout << (char)((av[j][i]) - 32) ;
			else
				std::cout << (char)(av[j][i]) ;
			i++;
		}
		j++;
	}
	std::cout << std::endl;
	return (0);
}
