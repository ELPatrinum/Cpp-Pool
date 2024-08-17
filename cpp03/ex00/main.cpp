/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:47:52 by muel-bak          #+#    #+#             */
/*   Updated: 2024/08/17 10:33:10 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main ()
{
	ClapTrap kayle;
	ClapTrap nasus("Nasus");

	nasus.attack("Vayne");
	nasus.takeDamage(5);
	nasus.beRepaired(5);
	nasus.takeDamage(10);
	nasus.attack("Caitlyne");
	nasus.beRepaired(10);
	nasus.attack("Jax");
	kayle = nasus;
	kayle.attack("Caitlyne");

	return (0);
}