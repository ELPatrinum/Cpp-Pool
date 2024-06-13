/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 09:20:40 by muel-bak          #+#    #+#             */
/*   Updated: 2024/06/02 15:43:03 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::announce( void )
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
Zombie::Zombie(std::string name_)
{
	name = name_;
}
std::string	Zombie::get_zombie()
{
	return (name);
}
Zombie::Zombie()
{
	
}
Zombie::~Zombie()
{
	std::cout << get_zombie() << " is REALLY DEAD now" << std::endl;
}
