/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 11:44:11 by muel-bak          #+#    #+#             */
/*   Updated: 2024/08/17 11:59:36 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap(std::string("Kayle" + "_clap_name")), name("Kayle")
{
	this->hitpoints = FragTrap::hitpoints;
	this->energypoints = ScavTrap::energypoints;
	this->attackdamage = FragTrap::attackdamage;
	std::cout << "DiamondTrap " << name << " created" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name): ClapTrap(name+"_clap_name"), ScavTrap(name+"_clap_name"), FragTrap(name+"_clap_name"), name(name)
{
	this->hitpoints = FragTrap::hitpoints;
	this->energypoints = ScavTrap::energypoints;
	this->attackdamage = FragTrap::attackdamage;
	std::cout << "DiamondTrap " << name << " created" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << name << " Destroyed" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other): ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	this->name = other.name;
	std::cout << "DiamondTrap " << this->name << " copied" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	return (*this); 
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "My name is " << this->name << ", My ClapTrap name is " << ClapTrap::name  << std::endl;
}
