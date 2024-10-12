/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:16:33 by muel-bak          #+#    #+#             */
/*   Updated: 2024/10/08 21:26:07 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
#include <iostream>
#include <exception>
#include "Form.hpp"

class Form;
class Bureaucrat
{
private:
	const std::string	name;
	unsigned  int		grade;
	static const int	maxG = 1;
	static const int	minG = 150;
	class GradeTooHighException : public std::exception
	{
	public:
		const char	*what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		const char	*what() const throw();
	};
public:
	Bureaucrat();
	Bureaucrat(std::string _name, unsigned int _grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);

	const std::string		getName()const;
	int	getGrade()const;
	int	incGrade();
	int	decGrade();
	void			signForm(Form& form);
	
};
std::ostream &operator<<(std::ostream &out, const Bureaucrat &fixed);

#endif