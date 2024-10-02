/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:11:49 by muel-bak          #+#    #+#             */
/*   Updated: 2024/10/02 16:37:58 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal("Dog")
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
Dog::Dog(const Dog& other): Animal(other)
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
	std::cout << "Dog has been copied" << std::endl;
}
Dog::~Dog()
{
	delete brain;
	std::cout << "Dog Destroyed" << std::endl;
}
Dog &Dog::operator=(const Dog &other)
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
			catch (const std::bad_alloc &e)
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
void Dog::makeSound() const
{
	std::cout << "Bark!!" << std::endl;
}

void Dog::add_idea(const std::string &idea)
{
	brain->add_idea(idea);
}

std::string Dog::get_idea(const unsigned int i)
{
	return (brain->get_idea(i));
}
