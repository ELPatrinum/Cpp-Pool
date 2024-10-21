/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 13:08:10 by muel-bak          #+#    #+#             */
/*   Updated: 2024/10/21 17:02:02 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void f()
{
	system("leaks btc");
}

int main(int ac, char **av)
{
	// atexit(f);
    if (ac !=  2 && !av[1])
        return (std::cerr << "Usage : ./btc [file.cvs] " << std::endl, 1);
	std::string file(av[1]);
    try
    {
        BitcoinExchange btc; 
		btc.check_find(file);
    }
    catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}