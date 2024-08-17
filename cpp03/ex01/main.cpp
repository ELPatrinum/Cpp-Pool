/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:47:52 by muel-bak          #+#    #+#             */
/*   Updated: 2024/08/17 10:33:35 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

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
	
	ScavTrap scarner;
	ScavTrap lulu("Lulu");
	scarner.attack("scarner");
	scarner.takeDamage(10);
	scarner.beRepaired(12);
	scarner.guardGate();
	lulu.attack("Kayle");
	lulu.takeDamage(55);
	lulu.beRepaired(22);
	scarner = lulu;
	scarner.attack("kaayle");

	return (0);
}