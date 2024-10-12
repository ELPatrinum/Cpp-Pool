/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:57:43 by muel-bak          #+#    #+#             */
/*   Updated: 2024/10/08 22:03:36 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::GradeTooHighException::GradeTooHighException(void)
{
	this->msg = "The grade is higher than the maximum!";
}
Form::GradeTooHighException::GradeTooHighException(const char *msg) : msg(msg)
{
}
const char	*Form::GradeTooHighException::what() const throw()
{
	return (this->msg);
}
Form::GradeTooLowException::GradeTooLowException(void)
{
	this->msg = "The grade is lower than the minimum!";
}
Form::GradeTooLowException::GradeTooLowException(const char *msg) : msg(msg)
{
}
const char	*Form::GradeTooLowException::what() const throw()
{
	return (this->msg);
}

Form::Form() : name(), fsigned(false), gradeToSign(1), gradeToExecute(1)
{
	
}
Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) 
			: name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < maxG || gradeToExecute < maxG)
		throw GradeTooHighException();
	else if (gradeToSign > minG || gradeToExecute > minG)
		throw GradeTooLowException();

	this->fsigned = false;
}
Form::Form(const Form &copy) :	name(copy.name), fsigned(copy.fsigned), gradeToSign(copy.gradeToSign),
								gradeToExecute(copy.gradeToExecute)
{
}
Form::~Form()
{
	std::cout << *this << " is Destroyed!" << std::endl;
}
Form&	Form::operator=(const Form& other)
{
	this->fsigned = other.fsigned;
	return (*this);
}
const std::string&	Form::getName(void) const
{
	return (this->name);
}
int	Form::getGradeToSign(void) const
{
	return (this->gradeToSign);
}

int Form::getGradeToExecute(void) const
{
	return (this->gradeToExecute);
}

bool	Form::isSigned(void) const
{
	return (this->fsigned);
}

void	Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > this->gradeToSign)
		throw GradeTooLowException("Bureaucrat is not authorized to sign the form!");
	this->fsigned = true;
}

std::ostream&	operator<<(std::ostream& out, Form& form)
{
	out << "Form: " << form.getName() << " Signed: " << (form.isSigned() ? "true" : "false");
	out << " GradeToSign: " << form.getGradeToSign();
	out << " GradeToExecute: " << form.getGradeToExecute();

	return (out);
}
