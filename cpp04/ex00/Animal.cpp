/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:00:36 by muel-bak          #+#    #+#             */
/*   Updated: 2024/08/20 14:00:51 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(): type("")
{
	std::cout << "Animal Created" << std::endl;
}
Animal::~Animal()
{
	std::cout << "Animal Destroyed" << std::endl;
}
std::string Animal::getType()
{
	return (this->type);
}
void Animal::makeSound()
{
	std::cout << "Animal Sound!!" << std::endl;
}