/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 09:42:55 by muel-bak          #+#    #+#             */
/*   Updated: 2024/08/17 09:55:46 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap():ClapTrap()
{
	std::cout << "ScavTrap " << name << " created" << std::endl;
	this->hitpoints = 100;
	this->attackdamage = 20;
	this->energypoints = 50;
}

ScavTrap::ScavTrap(const std::string& name): ClapTrap(name)
{
	std::cout << "ScavTrap " << name << " created" << std::endl;
	this->hitpoints = 100;
	this->attackdamage = 20;
	this->energypoints = 50;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->name << " Destroyed" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other): ClapTrap(other)
{
	std::cout << "ScavTrap " << this->name << " Copied" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	return (*this); 
}

void ScavTrap::attack(const std::string& target)
{
	if (!this->energypoints || !this->hitpoints)
	{
		if(!this->energypoints)
			std::cout << "ScavTrap " << this->name << " is out of energy" << std::endl;
		else
			std::cout << "ScavTrap " << this->name << " is out of hit points" << std::endl;
		return;
	}
	(this->energypoints)--;
	std::cout << "ScavTrap " << this->name << " attacks " << target << " dealing " << attackdamage << " of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode" << std::endl;
}
