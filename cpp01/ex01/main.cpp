/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 09:20:30 by muel-bak          #+#    #+#             */
/*   Updated: 2024/06/10 19:12:49 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	int N = 7;
	Zombie	*new_zombie;
	new_zombie = zombieHorde(N, "ZOM");
	for (int i = 0;  i < N; i++)
		new_zombie[i].announce();
	delete [] new_zombie;
}
