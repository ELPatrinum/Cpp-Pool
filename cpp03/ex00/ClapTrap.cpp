/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:48:00 by muel-bak          #+#    #+#             */
/*   Updated: 2024/08/17 10:40:30 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): name("Mundo"), hitpoints(10), energypoints(10), attackdamage(0) 
{
	std::cout << "ClapTrap " << name << " created!" << std::endl;
}
ClapTrap::ClapTrap(const std::string& name): name(name), hitpoints(10), energypoints(10), attackdamage(0) 
{
	std::cout << "ClapTrap " << name << " created!" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " Destroyed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	*this = other;
	std::cout << "ClapTrap " << name << " Copied!" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		name = other.name;
		attackdamage = other.attackdamage;
		hitpoints = other.hitpoints;
		energypoints = other.energypoints;
	}
	return *(this);  
}

void ClapTrap::attack(const std::string& target)
{
	if (!energypoints || !hitpoints)
	{
		if(!energypoints)
			std::cout << "ClapTrap " << name << " is out of energy!" << std::endl;
		else
			std::cout << "ClapTrap " << name << " is out of hit points!" << std::endl;
		return;
	}
	energypoints--;
	std::cout << "ClapTrap " << name << " attacks " << target << " dealing" << attackdamage << " of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hitpoints == 0)
    {
        std::cout << "ClapTrap " << name << " is out of hit points!" << std::endl;
		return;
    }
    hitpoints -= amount;
    std::cout << "ClapTrap " << name << " takes " << amount << " damage, the remaining hit points are " << hitpoints << "!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!energypoints)
	{
		std::cout << "ClapTrap " << name << " is out of energy!" << std::endl;
		return;
	}
	hitpoints += amount;
	energypoints--;
	std::cout << "ClapTrap " << name << " repairs itself for " << amount << " hit points, The status now is " << hitpoints << " hit points, and " << energypoints << " energy points !" << std::endl;
}