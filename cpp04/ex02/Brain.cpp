/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 15:18:39 by muel-bak          #+#    #+#             */
/*   Updated: 2024/10/02 12:16:27 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Created" << std::endl;
}
Brain::Brain(const Brain &other)
{
	*this = other;
	std::cout << "Brain Copied" << std::endl;
}
Brain::~Brain()
{
	std::cout << "Brain Destroyed" << std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		int i = 0;
		while (i < 100)
		{
			ideas[i] = other.ideas[i];
			i++;
		}
	}
	return (*this);
}

void Brain::add_idea(const std::string& idea)
{
	static unsigned int i;

	ideas[i%100] = idea;
	i++;
}

std::string Brain::get_idea(const unsigned int i)
{
	if (i < 100)
		return ideas[i];
	return ("");
}
