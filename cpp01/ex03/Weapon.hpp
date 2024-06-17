/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 20:51:16 by muel-bak          #+#    #+#             */
/*   Updated: 2024/06/10 21:05:32 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>

class Weapon
{
public:
	Weapon(std::string _type);
	~Weapon();
	std::string	&get_type();
	void				set_type(std::string ntype);
private:
	std::string	type;
};

#endif