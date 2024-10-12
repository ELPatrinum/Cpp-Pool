/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:57:52 by muel-bak          #+#    #+#             */
/*   Updated: 2024/10/12 13:22:08 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string	name;
	bool				fsigned;
	const int			gradeToSign;
	const int			gradeToExecute;
	static const int	maxG = 1;
	static const int	minG = 150;

public:
	class GradeTooHighException : public std::exception
	{
		private:
			const char	*msg;
		public:
			GradeTooHighException();
			GradeTooHighException(const char *msg);
			const char	*what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		private:
			const char	*msg;
		public:
			GradeTooLowException();
			GradeTooLowException(const char *msg);
			const char	*what() const throw();
	};
	Form();
	Form(const std::string &name, int gradeToSign, int gradeToExecutre);
	Form(const Form &other);
	~Form();

	Form&				operator=(const Form &other);
	const std::string&	getName() const;
	int					getGradeToSign() const;
	int					getGradeToExecute() const;
	bool				isSigned() const;
	void				beSigned(const Bureaucrat &b);

};
std::ostream&	operator<<(std::ostream &out, Form &form);

#endif