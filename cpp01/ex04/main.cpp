/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:07:17 by muel-bak          #+#    #+#             */
/*   Updated: 2024/09/24 16:25:57 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fr.hpp"

int main(int ac, char **av)
{
    if (ac == 4)
    {
        if (!*av[2])
		{
        	std::cerr << "Fr : Error : Empty <Find> " << std::endl;
            return (1);
		}
        Fr fr(av[1]);
        bool result = fr.find_and_replace(av[2], av[3]);
        if (!result)
            return (1);
        return (0);
    }
    else
        std::cerr << "Fr : Usage : <filename> <Find> <Replace>. " << std::endl;
    return (1);
}