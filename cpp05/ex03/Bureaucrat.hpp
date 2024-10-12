/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:16:33 by muel-bak          #+#    #+#             */
/*   Updated: 2024/10/10 11:56:08 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
#include <iostream>
#include <exception>
#include "AForm.hpp"

class AForm;
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
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	~Bureaucrat();
	const std::string		getName()const;
	int	getGrade()const;
	int	incGrade();
	int	decGrade();
	void	signForm(AForm& form);
	void	executeForm(const AForm& form);
	
};
std::ostream &operator<<(std::ostream &out, const Bureaucrat &fixed);

#endif
