/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:07:17 by muel-bak          #+#    #+#             */
/*   Updated: 2024/09/11 20:49:47 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fr.hpp"

int main(int ac, char **av)
{
    if (ac == 4)
    {
        if (!*av[2])
            return (0);
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