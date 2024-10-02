/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:24:07 by muel-bak          #+#    #+#             */
/*   Updated: 2024/10/02 14:30:56 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(): AMateria("cure") {}

Cure::~Cure() {}

Cure::Cure(const Cure &other): AMateria(other) {}

Cure &Cure::operator=(const Cure &other)
{
	(void) other;
	return (*this);
}

AMateria *Cure::clone() const
{
	AMateria *cclone = NULL;
	try
	{
		cclone = new Cure();
	}
	catch (const std::bad_alloc &e)
	{
		std::cerr << "Allocation failed: " << e.what() << std::endl;
	}
	return (cclone);
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
