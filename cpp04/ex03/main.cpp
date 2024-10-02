/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 12:46:39 by muel-bak          #+#    #+#             */
/*   Updated: 2024/10/02 16:58:17 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"

void test()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* alice = new Character("Alice");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	alice->equip(tmp);
	tmp = src->createMateria("cure");
	alice->equip(tmp);
	alice->equip(tmp);
	alice->equip(tmp->clone());
	alice->equip(tmp->clone());
	alice->equip(tmp->clone());

	ICharacter* bob = new Character("Bob");

	alice->use(0, *bob);
	alice->use(1, *bob);
	alice->use(2, *bob);
	alice->use(-22, *bob);
	alice->use(55, *bob);

	*(Character *)bob = *(Character *)alice;
	bob->use(1, *alice);

	bob->unequip(1);
	bob->use(1, *alice);

	tmp = src->createMateria("ice");
	bob->equip(tmp);
	bob->use(1, *alice);

	alice->use(1, *bob);

	delete bob;
	delete alice;
	delete src;
}
void f()
{
	system("leaks recap");
}

int main()
{
	// atexit(f);

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;

	test();
}
