/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:31:32 by muel-bak          #+#    #+#             */
/*   Updated: 2024/08/21 12:47:35 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal("Cat")
{
	std::cout << "Cat Created" << std::endl;
}
Cat::Cat(const Cat& other): Animal(other)
{
	std::cout << "Cat has been copied" << std::endl;
}
Cat::~Cat()
{
	std::cout << "Cat Destroyed" << std::endl;
}
Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		type = other.type;
	}
	return (*this);
}
void Cat::makeSound() const
{
	std::cout << "Meow!!" << std::endl;
}
