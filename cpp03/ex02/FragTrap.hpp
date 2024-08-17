/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 10:12:18 by muel-bak          #+#    #+#             */
/*   Updated: 2024/08/17 10:35:18 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	private:
		
	public:
		FragTrap();
		FragTrap(const std::string& name);
		~FragTrap();
		FragTrap(const FragTrap& other);
		FragTrap &operator=(const FragTrap& other);
		
		void attack(const std::string& target);
		void highFives();
};

#endif