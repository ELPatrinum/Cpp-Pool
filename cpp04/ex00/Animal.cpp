/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:00:36 by muel-bak          #+#    #+#             */
/*   Updated: 2024/08/21 12:49:59 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(): type("Animal")
{
	std::cout << "Animal Created" << std::endl;
}
Animal::Animal(std::string type): type(type)
{
	std::cout << "Animal " << type << " Created" << std::endl;
}
Animal::~Animal()
{
	std::cout << "Animal " << type << " Destroyed" << std::endl;
}
Animal::Animal(const Animal &other)
{
	*this = other;
	std::cout << "Animal Copied" << std::endl;
}
Animal &Animal::operator=(const Animal &other)
{
	if (this != &other)
	{
		type = other.type;
	}
	return (*this);
}
std::string Animal::getType() const
{
	return (this->type);
}
void Animal::makeSound() const
{
	std::cout << "Animal Sound!!" << std::endl;
}
