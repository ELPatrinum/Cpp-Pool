/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:15:32 by muel-bak          #+#    #+#             */
/*   Updated: 2024/10/12 12:15:19 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat		Kayle("Kayle", 1);
	Bureaucrat		Jax("Jax", 40);
	Bureaucrat		Swain("Swain", 150);
	AForm			*form = NULL;
	std::cout << "execute an unsigned presidential pardon form" << std::endl;
	try
	{
		form = new PresidentialPardonForm("1");
		form->execute(Kayle);
		delete form;
		form = NULL;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << "\nsign and execute a presidential pardon form" << std::endl;
	try
	{
		form = new PresidentialPardonForm("2");
		form->beSigned(Kayle);
		form->execute(Kayle);
		delete form;
		form = NULL;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << "\nLet's sign and execute robotomy request form with different people" << std::endl;
	try
	{
		form = new RobotomyRequestForm("3");
		Kayle.signForm(*form);
		std::cout << std::endl;
		Jax.executeForm(*form);
		Jax.executeForm(*form);
		Jax.executeForm(*form);
		Jax.executeForm(*form);
		Jax.executeForm(*form);
		Jax.executeForm(*form);
		delete form;
		form = NULL;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << "\nexecute shrubbery creation form with unauthorized bureaucrat" << std::endl;
	try
	{
		form = new ShrubberyCreationForm("4");
		Kayle.signForm(*form);
		Jax.executeForm(*form);
		Swain.executeForm(*form);
		delete form;
		form = NULL;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	return (0);
}