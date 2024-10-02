/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:43:23 by muel-bak          #+#    #+#             */
/*   Updated: 2024/10/02 14:45:17 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(): name("Unkown")
{
	for (int i = 0; i < 4; i++)
	{
		equipted[i] = 0;
		inventory[i] = NULL;
	}
}

Character::Character(std::string const& name): name(name)
{
	for (int i = 0; i < 4; i++)
	{
		equipted[i] = 0;
		inventory[i] = NULL;
	}
}

Character::Character(const Character &other)
{
	name = other.name;
	for (int i = 0; i < 4; i++)
	{
		equipted[i] = 0;
		inventory[i] = NULL;
	}
	for (int i = 0; i < 4; i++)
	{
		if (other.equipted[i])
		{
			inventory[i] = other.inventory[i]->clone();
			if (!inventory[i])
			{
				for (int j = 0; j < 4; j++)
				{
					equipted[j] = 0;
					delete inventory[j];
					inventory[j] = NULL;
				}
			}
			equipted[i] = other.equipted[i];
		}
	}
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		delete inventory[i];
}

Character &Character::operator=(const Character &other)
{
	if (this != &other)
	{
		name = other.name;
		int i;
		for (i = 0; i < 4; i++)
		{
			equipted[i] = 0;
			delete inventory[i];
			inventory[i] = NULL;
		}
		for (i = 0; i < 4; i++)
		{
			if (other.equipted[i])
			{
				inventory[i] = other.inventory[i]->clone();
				if (!inventory[i])
				{
					for (int j = 0; j < 4; j++)
					{
						equipted[j] = 0;
						delete inventory[j];
						inventory[j] = NULL;
					}
				}
				equipted[i] = other.equipted[i];
			}
		}
	}
	return (*this);
}

std::string const &Character::getName() const
{
	return (name);
}

void Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] == m)
			return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (!equipted[i] && m)
		{
			delete inventory[i];
			inventory[i] = m;
			equipted[i] = 1;
			return;
		}
	}
	delete m;
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
		equipted[idx] = 0;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && equipted[idx])
		inventory[idx]->use(target);
}
