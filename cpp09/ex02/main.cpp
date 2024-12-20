/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:36:54 by muel-bak          #+#    #+#             */
/*   Updated: 2024/11/11 12:40:24 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac < 2)
		return (1);
	try
	{
		PmergeMe pm;
		pm.launch(pm.mergeStrings(av + 1, ac -1));
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
//  ./PmergeMe `jot -r 3000 1 100000 | tr '\n' ' '`