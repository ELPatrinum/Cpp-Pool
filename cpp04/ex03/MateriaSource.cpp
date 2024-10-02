/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:29:22 by muel-bak          #+#    #+#             */
/*   Updated: 2024/10/02 15:41:58 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(): size(0) 
{
	for (int i = 0; i < 4; i++)
		materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	size = 0;
	for (int i = 0; i < 4; i++)
		materias[i] = NULL;
	for (int i = 0; i < other.size; i++)
	{
		materias[i] = other.materias[i]->clone();
		if (!materias[i])
		{
			for (int j = 0; j < i; j++)
				delete materias[j];
			size = 0;
			break;
		}
		size++;
	}
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < size; i++)
		delete materias[i];
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other)
	{
		int i;
		for (i = 0; i < size; i++)
		{
			delete materias[i];
			materias[i] = NULL;
		}
		size = 0;
		for (i = 0; i < other.size; i++)
		{
			materias[i] = other.materias[i]->clone();
			if (!materias[i])
			{
				for (i = 0; i < size; i++)
				{
					delete materias[i];
					materias[i] = NULL;
				}
				size = 0;
				break;
			}
			size++;
		}
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < size; i++)
	{
		if (materias[i] == m)
			return;
	}
	if (size < 4 && m)
		materias[size++] = m;
	else 
		delete (m);
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < size; i++)
	{
		if (materias[i]->getType() == type)
			return materias[i]->clone();
	}
	return (NULL);
}
