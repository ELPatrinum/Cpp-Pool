/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:15:32 by muel-bak          #+#    #+#             */
/*   Updated: 2024/10/12 13:07:51 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"

void f()
{
	system("leaks Intern");
}

int main()
{
	atexit(f);
	Intern	intern;
	AForm	*f;
	
	f = intern.makeForm("PresidentialPardon", "A");
	std::cout << *f << std::endl;
	std::cout << std::endl;
	delete (f);

	f = intern.makeForm("RobotomyRequest", "B");
	std::cout << *f << std::endl;
	std::cout << std::endl;
	delete (f);

	f = intern.makeForm("ShrubberyCreation", "C");
	std::cout << *f << std::endl;
	std::cout << std::endl;
	delete (f);
	
	f = intern.makeForm("TRY", "Z");
	delete (f);
}