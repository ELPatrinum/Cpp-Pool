/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:53:03 by muel-bak          #+#    #+#             */
/*   Updated: 2024/10/02 16:58:11 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

void cat_test()
{
	Cat c;
	Cat b;
	c.makeSound();
	for (int i = 0; i < 100; i++)
		c.add_idea("only cares about food");
	std::cout << c.get_idea(1) << std::endl;
	b = c;
	std::cout << b.get_idea(55)<< std::endl;
	Cat d(c);
	std::cout << b.get_idea(120)<< std::endl;

}

void dog_test()
{
	Dog *x = new Dog();
	Dog *y = new Dog();
	x->makeSound();
	for (int i = 0; i < 100; i++)
	{
		x->add_idea("he is my friend");
		x->add_idea("im just a loyal pet");
	}
	std::cout << x->get_idea(5) << std::endl;
	*y = *x;
	std::cout << y->get_idea(50)<< std::endl;
	Dog *z = new Dog(*y);
	std::cout << z->get_idea(2)<< std::endl;
	delete x;
	delete y;
	delete z;
}

void brain_test()
{
	Brain brain_a;
	Brain brain_b;

	brain_a.add_idea("idea 1");
	brain_a.add_idea("idea 2");

	std::cout << brain_a.get_idea(0) << std::endl;
	brain_b = brain_a;
	std::cout << brain_b.get_idea(1) << std::endl;

	Brain brain_c(brain_b);
	std::cout << brain_c.get_idea(1) << std::endl;
}
void f()
{
	system("leaks Brain");
}

int main()
{
	// atexit(f);
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;

	brain_test();
	cat_test();
	dog_test();

	int animal_size = 10;
	Animal *animals[animal_size];

	for(int i = 0; i < animal_size; i++)
	{
		if (i % 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	animals[0]->makeSound();

	((Dog *)animals[1])->add_idea("Let's play");
	((Dog *)animals[1])->add_idea("I wanna eat");

	std::cout << ((Dog *)animals[1])->get_idea(0) << std::endl;
	
	for (int i = 0; i < animal_size; i++)
		delete animals[i];
	return 0;
}
