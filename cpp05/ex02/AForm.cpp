/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:57:43 by muel-bak          #+#    #+#             */
/*   Updated: 2024/10/08 22:03:36 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::GradeTooHighException::GradeTooHighException()
{
	this->msg = "The grade is higher than the maximum!";
}
AForm::GradeTooHighException::GradeTooHighException(const char *msg) : msg(msg)
{
}
const char*	AForm::GradeTooHighException::what() const throw()
{
	return (this->msg);
}
AForm::GradeTooLowException::GradeTooLowException()
{
	this->msg = "The grade is lower than the minimum!";
}
AForm::GradeTooLowException::GradeTooLowException(const char *msg) : msg(msg)
{
}
const char*	AForm::GradeTooLowException::what() const throw()
{
	return (this->msg);
}

AForm::AForm() : name(), fsigned(false), gradeToSign(1), gradeToExecute(1)
{
	
}
AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) 
			: name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < maxG || gradeToExecute < maxG)
		throw GradeTooHighException();
	else if (gradeToSign > minG || gradeToExecute > minG)
		throw GradeTooLowException();

	this->fsigned = false;
}
AForm::AForm(const AForm &copy) :	name(copy.name), fsigned(copy.fsigned), gradeToSign(copy.gradeToSign),
								gradeToExecute(copy.gradeToExecute)
{
}
AForm::~AForm()
{
	std::cout << *this << " is Destroyed!" << std::endl;
}
AForm&	AForm::operator=(const AForm& other)
{
	this->fsigned = other.fsigned;
	return (*this);
}
const std::string&	AForm::getName() const
{
	return (this->name);
}
int	AForm::getGradeToSign() const
{
	return (this->gradeToSign);
}

int AForm::getGradeToExecute() const
{
	return (this->gradeToExecute);
}

bool	AForm::isSigned() const
{
	return (this->fsigned);
}

void	AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > this->gradeToSign)
		throw GradeTooLowException("Bureaucrat is not authorized to sign the Aform!");
	this->fsigned = true;
}

std::ostream&	operator<<(std::ostream &out, AForm &Aform)
{
	out << "AForm: " << Aform.getName() << " Signed: " << (Aform.isSigned() ? "true" : "false");
	out << " GradeToSign: " << Aform.getGradeToSign();
	out << " GradeToExecute: " << Aform.getGradeToExecute();

	return (out);
}

void AForm::checkExecutability(const Bureaucrat &executor) const
{
	if (executor.getGrade() > gradeToExecute)
		throw GradeTooLowException("Bureaucrat is not authorized to execute the form!");
	if (!this->fsigned)
		throw InvalidFormException("Not signed forms cannot be executed!");
}
AForm::InvalidFormException::InvalidFormException()
{
	this->msg = "The form cannot be executed!";
}

AForm::InvalidFormException::InvalidFormException(const char *msg) : msg(msg)
{

}

const char*	AForm::InvalidFormException::what() const throw()
{
	return (this->msg);
}
