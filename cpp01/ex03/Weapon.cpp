/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 20:51:13 by muel-bak          #+#    #+#             */
/*   Updated: 2024/06/10 21:05:24 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string _type)
{
	type = _type;
}
Weapon::~Weapon()
{	
}
std::string& Weapon::get_type()
{
	return (type);
}


void Weapon::set_type(std::string _type)
{
	type = _type;
}
