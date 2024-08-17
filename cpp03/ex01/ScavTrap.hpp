/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 09:42:39 by muel-bak          #+#    #+#             */
/*   Updated: 2024/08/17 10:22:55 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
		
	public:
		ScavTrap();
		ScavTrap(const std::string& name);
		~ScavTrap();
		ScavTrap(const ScavTrap& other);
		ScavTrap &operator=(const ScavTrap& other);
		
		void attack(const std::string& target);
		void guardGate();
};

#endif