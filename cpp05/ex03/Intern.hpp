/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 12:38:53 by muel-bak          #+#    #+#             */
/*   Updated: 2024/10/12 12:55:09 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	private:
		typedef struct	s_form
		{
			std::string	type;
			AForm		*form;
		}t_form;
	public:
		Intern();
		Intern(const Intern &other);
		Intern&	operator=(const Intern &other);
		~Intern();
		AForm	*makeForm(const std::string &Name, const std::string &target) const;
};

#endif