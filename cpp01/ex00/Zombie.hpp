/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 09:20:42 by muel-bak          #+#    #+#             */
/*   Updated: 2024/06/02 15:43:19 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

# include <iostream>

class Zombie
{
	std::string	name;
public :
	void		announce( void );
	Zombie(std::string name);
	std::string	get_zombie();
	Zombie();
	~Zombie();

};
Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

#endif