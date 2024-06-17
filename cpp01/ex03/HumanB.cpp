/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 20:51:58 by muel-bak          #+#    #+#             */
/*   Updated: 2024/06/10 20:51:59 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name)
{
}

HumanB::~HumanB()
{
}

void	HumanB::attack() const
{
	std::cout << name << " attacks with their " << weapon->get_type() << std::endl;
}

void	HumanB::set_weapon(Weapon &_weapon)
{
	weapon = &_weapon;
}