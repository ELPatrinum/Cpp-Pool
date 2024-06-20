/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:49:31 by muel-bak          #+#    #+#             */
/*   Updated: 2024/06/19 12:09:09 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
    Harl        harl;
    std::string level;

    while (level.compare("Q"))
    {
        std::cout << "Enter a level: ";
        std::cin >> level;
        harl.Complain(level);
    }
    return (0);
}
