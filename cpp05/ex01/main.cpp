/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:15:32 by muel-bak          #+#    #+#             */
/*   Updated: 2024/10/08 22:12:30 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    std::cout << "Let's create a form with grade to sign 0" << std::endl;
	try
	{
		Form	f("A", 0, 1);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\nLet's create a form with grade to execute 0" << std::endl;
	try
	{
		Form	f("B", 1, 0);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\nLet's create a form with grade to execute 151" << std::endl;
	try
	{
		Form	f("C", 1, 151);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\nLet's create a form with grade to sign 151" << std::endl;
	try
	{
		Form	f("D", 151, 1);
	}
	catch (std::exception &e)
	{
		std::cout << "Exeption: " << e.what() << std::endl;
	}

	std::cout << "\nLet's sign a form with appropriate bureaucrat\n" << std::endl;
	try
	{
		Bureaucrat	Kayle("Kayle", 1);
		Form		f("E", 100, 100);
		std::cout << f << std::endl;
		Kayle.signForm(f);
		std::cout << f << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;


	std::cout << "\nLet's sign a form with inappropriate bureaucrat\n" << std::endl;
	try
	{
		Bureaucrat	Jax("Jax", 20);
		Form		f("F", 1, 1);

		std::cout << f << std::endl;
		Jax.signForm(f);
		std::cout << f << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
