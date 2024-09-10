/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:53:03 by muel-bak          #+#    #+#             */
/*   Updated: 2024/09/09 11:11:19 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

void cat_test()
{
	Cat *c = new Cat();
	Cat *b = new Cat();
	c->makeSound();
	int i = 0;
	while ( i < 100)
	{
		c->add_idea("Food Food");
		i++;
	}
	std::cout << c->get_idea(1) << std::endl;
	b = c;
	std::cout << b->get_idea(55)<< std::endl;

	Cat d(*c);
	std::cout << b->get_idea(120)<< std::endl;

	delete c;
	delete b;
}

void dog_test()
{
	Dog c;
	Dog b;
	c.makeSound();
	int i = 0;
	while ( i < 100)
	{
		c.add_idea("Loyalty");
		i++;
	}
	std::cout << c.get_idea(1) << std::endl;
	b = c;
	std::cout << b.get_idea(55)<< std::endl;

	Dog d(c);
	std::cout << b.get_idea(120)<< std::endl;
}

void brain_test()
{
	Brain brain_a;
	Brain brain_b;

	brain_a.add_idea("a smart idea");
	brain_a.add_idea("a dumb idea");

	std::cout << brain_a.get_idea(0) << std::endl;

	brain_b = brain_a;
	std::cout << brain_b.get_idea(1) << std::endl;
	
	Brain brain_c(brain_b);
	std::cout << brain_c.get_idea(1) << std::endl;
}

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;
	brain_test();
	cat_test();
	dog_test();
	int animal_size = 20;
	Animal *animals[animal_size];

	int ii = 0;
	while( ii < animal_size)
	{
		if (ii % 2)
			animals[ii] = new Dog();
		else
			animals[ii] = new Cat();
		ii++;
	}
	animals[0]->makeSound();
	((Dog *)animals[1])->add_idea("Friendship");
	((Dog *)animals[1])->add_idea("Loyalty");
	std::cout << ((Dog *)animals[1])->get_idea(0) << std::endl;
	ii = 0;
	while (ii < animal_size)
	{
		delete animals[ii];
		ii++;
	}
	return (0);
}
