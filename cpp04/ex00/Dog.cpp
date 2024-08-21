/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:11:49 by muel-bak          #+#    #+#             */
/*   Updated: 2024/08/21 13:23:23 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal("Dog")
{
	std::cout << "Dog Created" << std::endl;
}
Dog::Dog(const Dog& other): Animal(other)
{
	std::cout << "Dog has been copied" << std::endl;
}
Dog::~Dog()
{
	std::cout << "Dog Destroyed" << std::endl;
}
Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		type = other.type;
	}
	return (*this);
}
void Dog::makeSound() const
{
	std::cout << "Bark!!" << std::endl;
}
