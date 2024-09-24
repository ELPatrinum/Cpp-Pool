/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:49:31 by muel-bak          #+#    #+#             */
/*   Updated: 2024/09/24 16:49:45 by muel-bak         ###   ########.fr       */
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
		if (std::cin.eof())
		{
			std::cerr << "\033[38;5;214mEOF received. Exiting...\033[0;37m" << std::endl;
			break;
		}
        harl.Complain(level);
    }
    return (0);
}
