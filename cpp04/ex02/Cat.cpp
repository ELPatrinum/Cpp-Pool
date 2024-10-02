/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:31:32 by muel-bak          #+#    #+#             */
/*   Updated: 2024/08/26 15:29:21 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal("Cat")
{
	try
	{
		brain = new Brain();
	}
	catch (const std::bad_alloc& e)
	{
		brain = NULL;
		std::cerr << "new: " << e.what() << std::endl;
	}
	std::cout << "Cat Created" << std::endl;
}
Cat::Cat(const Cat& other): Animal(other)
{
	if (other.brain)
	{
		try
		{
			brain = new Brain();
			*brain = *(other.brain);
		}
		catch (const std::bad_alloc& e)
		{
			brain = NULL;
			std::cerr << "new: " << e.what() << std::endl;
		}
	}
	else
		brain = NULL;
	std::cout << "Cat has been copied" << std::endl;
}
Cat::~Cat()
{
	delete brain;
	std::cout << "Cat Destroyed" << std::endl;
}
Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		delete brain;
		if (other.brain)
		{
			try
			{
				brain = new Brain();
				*brain = *(other.brain);
			}
			catch (const std::bad_alloc& e)
			{
				brain = NULL;
				std::cerr << "new: " << e.what() << std::endl;
			}
		}
		else
			brain = NULL;
	}
	return (*this);
}
void Cat::makeSound() const
{
	std::cout << "Meow!!" << std::endl;
}
void Cat::add_idea(const std::string& idea)
{
	brain->add_idea(idea);
}

std::string Cat::get_idea(const unsigned int i)
{
	return (brain->get_idea(i));
}

