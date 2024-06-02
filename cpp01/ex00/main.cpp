/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 09:20:30 by muel-bak          #+#    #+#             */
/*   Updated: 2024/06/02 14:38:22 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie	*new_zombie;
	randomChump("SHORT LIFE");
	new_zombie = newZombie("LONG LIFE");
	new_zombie->announce();
	delete new_zombie;
}
