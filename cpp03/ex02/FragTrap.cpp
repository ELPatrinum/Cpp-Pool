/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 10:12:24 by muel-bak          #+#    #+#             */
/*   Updated: 2024/08/17 10:35:28 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap " << name << " created" << std::endl;
	this->hitpoints = 100;
	this->attackdamage = 30;
	this->energypoints = 100;
}

FragTrap::FragTrap(const std::string& name): ClapTrap(name)
{
	std::cout << "FragTrap " << name << " created" << std::endl;
	this->hitpoints = 100;
	this->attackdamage = 30;
	this->energypoints = 100;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->name << " Destroyed" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other): ClapTrap(other)
{
	std::cout << "FragTrap " << this->name << " copied" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	return (*this); 
}

void FragTrap::attack(const std::string& target)
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

void FragTrap::highFives()
{
	std::cout << "FragTrap " << this->name << " requested a high fives" << std::endl;
}