/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 09:20:42 by muel-bak          #+#    #+#             */
/*   Updated: 2024/06/10 22:30:20 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

# include <iostream>

class Zombie
{
	std::string	name;
public :
	Zombie();
	~Zombie();
	void		announce( void );
	void set_zombie(std::string name_);

};
Zombie* zombieHorde(int N, std::string name);

#endif