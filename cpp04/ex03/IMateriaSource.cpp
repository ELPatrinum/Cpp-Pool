/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:28:21 by muel-bak          #+#    #+#             */
/*   Updated: 2024/10/02 16:06:05 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(): size(0) 
{
	for (int i = 0; i < 4; i++)
		mantras[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	size = 0;
	for (int i = 0; i < 4; i++)
		mantras[i] = NULL;
	for (int i = 0; i < other.size; i++)
	{
		mantras[i] = other.mantras[i]->clone();
		if (!mantras[i])
		{
			for (int j = 0; j < i; j++)
				delete mantras[j];
			size = 0;
			break;
		}
		size++;
	}
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < size; i++)
		delete mantras[i];
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other)
	{
		int i;
		for (i = 0; i < size; i++)
		{
			delete mantras[i];
			mantras[i] = NULL;
		}
		size = 0;
		for (i = 0; i < other.size; i++)
		{
			mantras[i] = other.mantras[i]->clone();
			if (!mantras[i])
			{
				for (i = 0; i < size; i++)
				{
					delete mantras[i];
					mantras[i] = NULL;
				}
				size = 0;
				break;
			}
			size++;
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < size; i++)
	{
		if (mantras[i] == m)
			return;
	}
	if (size < 4 && m)
		mantras[size++] = m;
	else 
		delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < size; i++)
	{
		if (mantras[i]->getType() == type)
			return mantras[i]->clone();
	}
	return NULL;
}
