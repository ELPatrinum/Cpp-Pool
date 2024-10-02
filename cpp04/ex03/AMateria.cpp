/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:52:33 by muel-bak          #+#    #+#             */
/*   Updated: 2024/10/02 15:55:14 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"

AMateria::AMateria(): type("None") {}

AMateria::AMateria(std::string const &type): type(type) {}

AMateria::AMateria(const AMateria &other): type(other.type) {}

AMateria::~AMateria(){}

AMateria &AMateria::operator=(const AMateria &other)
{
	(void) other;
	return (*this);
}

std::string const &AMateria::getType() const
{
	return (type);
}

void AMateria::use(ICharacter &target)
{
	std::cout << "* A materia used on " << target.getName() << " *" << std::endl;
}
