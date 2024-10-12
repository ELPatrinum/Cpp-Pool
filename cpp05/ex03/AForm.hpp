/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:57:52 by muel-bak          #+#    #+#             */
/*   Updated: 2024/10/08 20:30:40 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
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
			GradeTooHighException(void);
			GradeTooHighException(const char *msg);
			const char	*what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		private:
			const char	*msg;
		public:
			GradeTooLowException(void);
			GradeTooLowException(const char *msg);
			const char      *what() const throw();
	};
	class InvalidFormException : public std::exception
	{
		private:
			const char	*msg;
		public:
			InvalidFormException(void);
			InvalidFormException(const char *msg);
			const char* what() const throw();
	};
	AForm();
	AForm(const std::string& name, int gradeToSign, int gradeToExecutre);
	AForm(const AForm& other);
	virtual ~AForm(void);
	AForm&				operator=(const AForm& other);
	const std::string&	getName(void) const;
	int					getGradeToSign(void) const;
	int					getGradeToExecute(void) const;
	bool				isSigned(void) const;
	void				beSigned(const Bureaucrat& b);
	virtual void		execute(const Bureaucrat& executor) const = 0;
protected:
		void				checkExecutability(const Bureaucrat& executor) const;
};
std::ostream&	operator<<(std::ostream& out, AForm& Aform);

#endif
