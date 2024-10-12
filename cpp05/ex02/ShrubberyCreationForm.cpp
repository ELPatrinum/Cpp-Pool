/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 02:13:38 by muel-bak          #+#    #+#             */
/*   Updated: 2024/10/12 11:47:52 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() 
	: AForm("ShrubberyCreationForm", 145, 137), target("")
{
	
}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) 
	: AForm("ShrubberyCreationForm", 145, 137), target(target)
{
	
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) 
	: AForm("ShrubberyCreationForm", 145, 137), target(other.getTarget())
{
	
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << this->target << " is Destroyed!" << std::endl;
}

const std::string	&ShrubberyCreationForm::getTarget() const
{
	return (this->target);
}
void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	std::ofstream	file;
	std::string		name;

	this->checkExecutability(executor);
	name = target + "_shrubbery";
	file.open(name.c_str(), std::ofstream::out);

    file << "        ccee88oo              " << std::endl;
    file << "     C8O8O8Q8PoOb o8oo       " << std::endl;
    file << "   dOB69QO8PdUOpugoO9bD      " << std::endl;
    file << "  CgggbU8OU qOp qOdoUOdcb    " << std::endl;
    file << "    6OuU  /p u gcoUodpP      " << std::endl;
    file << "      \\\\//  /douUP          " << std::endl;
    file << "        \\\\////               " << std::endl;
    file << "         |||/\\                " << std::endl;
    file << "         |||\\/                " << std::endl;
    file << "         |||||                 " << std::endl;
    file << "         |||||                 " << std::endl;
    file << "         |||||                 " << std::endl;
    file << "   .....//|||||\\\\....         " << std::endl;
	file.close();
}