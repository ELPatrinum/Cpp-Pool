/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 12:52:39 by muel-bak          #+#    #+#             */
/*   Updated: 2024/10/12 13:05:24 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(){};
Intern::Intern(const Intern &other)
{
	*this = other;
};
Intern&	Intern::operator=(const Intern &other)
{
	(void)other;
	return(*this);
};
Intern::~Intern(){};
AForm	*Intern::makeForm(const std::string &Name, const std::string &target)const
{
	AForm	*result;
	t_form	data[] = 
	{
		{ "PresidentialPardon", new PresidentialPardonForm(target) },
		{ "RobotomyRequest", new RobotomyRequestForm(target) },
		{ "ShrubberyCreation", new ShrubberyCreationForm(target) },
		{ "", NULL }
	};

	result = NULL;
	for (int i = 0; data[i].form != NULL; i++)
	{
		if (data[i].type == Name)
			result = data[i].form;
		else
			delete data[i].form;
	}

	if (result == NULL)
		std::cout << "A non valid form name " << Name << std::endl;
	else
		std::cout << "Intern creates " << Name << std::endl;
	return (result);
};