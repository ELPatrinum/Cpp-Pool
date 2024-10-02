/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:14:06 by muel-bak          #+#    #+#             */
/*   Updated: 2024/10/02 14:31:01 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(): AMateria("ice") {}

Ice::~Ice() {}

Ice::Ice(const Ice &other): AMateria(other) {}

Ice &Ice::operator=(const Ice &other)
{
	(void) other;
	return (*this);
}

AMateria *Ice::clone() const
{
	AMateria *iclone = NULL;
	try
	{
		iclone = new Ice();
	}
	catch (const std::bad_alloc &e)
	{
		std::cerr << "Allocation failed: " << e.what() << std::endl;
	}
	return (iclone);
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
