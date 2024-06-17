/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:07:17 by muel-bak          #+#    #+#             */
/*   Updated: 2024/06/17 18:44:45 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FR.hpp"

int main(int ac, char **av)
{
    if (ac == 4)
    {
        FR fr(av[1]);
        bool result = fr.find_and_replace(av[2], av[3]);
        if (!result)
            return (1);
        return (0);
    }
    else
        std::cerr << "FR : Usage : <filename> <Find> <Replace>. " << std::endl;
    return (1);
}