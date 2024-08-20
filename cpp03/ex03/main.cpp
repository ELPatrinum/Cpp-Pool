/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:47:52 by muel-bak          #+#    #+#             */
/*   Updated: 2024/08/20 10:22:24 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main ()
{
	ClapTrap Mundo;
	ClapTrap nasus("Nasus");

	nasus.attack("Vayne");
	nasus.takeDamage(5);
	nasus.beRepaired(5);
	nasus.takeDamage(10);
	nasus.attack("Caitlyne");
	nasus.beRepaired(10);
	nasus.attack("Jax");
	Mundo = nasus;
	Mundo.attack("Caitlyne");
	
	ScavTrap scarner;
	ScavTrap lulu("Lulu");
	scarner.attack("scarner");
	scarner.takeDamage(10);
	scarner.beRepaired(12);
	lulu.guardGate();
	lulu.attack("Kayle");
	lulu.takeDamage(55);
	lulu.beRepaired(22);
	scarner = lulu;
	scarner.attack("kayle");
	
	FragTrap xayah;
	FragTrap jinx("Jinx");
	xayah.attack("Xayah");
	xayah.takeDamage(20);
	xayah.beRepaired(22);
	jinx.highFivesGuy();
	jinx.attack("Kayle");
	jinx.takeDamage(45);
	jinx.beRepaired(30);
	xayah = jinx;
	xayah.attack("kayle");
	
	return (0);
}