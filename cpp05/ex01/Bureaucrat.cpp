/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:16:42 by muel-bak          #+#    #+#             */
/*   Updated: 2024/10/08 22:07:13 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("randome"), grade(100)
{
}
Bureaucrat::Bureaucrat(std::string _name, unsigned int _grade) : name(_name)
{
	if (_grade < maxG)
		throw GradeTooHighException();
	else if (_grade > minG)
		throw GradeTooLowException();
	grade = _grade;
}
Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade)
{
}
Bureaucrat::~Bureaucrat()
{
	std::cout << *this << " is Destroyed!" << std::endl;
}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
	{
        this->grade = other.getGrade();
    }
    return (*this);
}
std::ostream &operator<<(std::ostream &out, const Bureaucrat &fixed)
{
	out << fixed.getName() << ", bureaucrat grade " << fixed.getGrade();
    return (out);
}

const std::string		Bureaucrat::getName()const
{
	return (name);
}
int	Bureaucrat::getGrade()const
{
	return (grade);
}

int	Bureaucrat::incGrade()
{
	if ((grade - 1) < maxG)
		throw GradeTooHighException();
	grade--;
	return (grade);
}
int	Bureaucrat::decGrade()
{
	if ((grade + 1) > minG)
		throw GradeTooLowException();
	grade++;
	return (grade);
}

const char		*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is higher than the maximum!");
}

const char		*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is lower than the minimum!");
}
void	Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->name << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cout << this->name << " couldn’t sign " << form.getName() << " because "<< e.what() << std::endl;
	}
}