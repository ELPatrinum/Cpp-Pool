/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 03:23:15 by muel-bak          #+#    #+#             */
/*   Updated: 2024/10/12 12:26:28 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() 
        : AForm("PresidentialPardonForm", 25, 5), target("")
{
	
}
PresidentialPardonForm::PresidentialPardonForm(const std::string &target) 
        : AForm("PresidentialPardonForm", 25, 5), target(target)
{
	
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) 
        : AForm("PresidentialPardonForm", 25, 5), target(other.getTarget())
{
	
}
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << this->target << " is Destroyed!" << std::endl;
}
const std::string &PresidentialPardonForm::getTarget() const
{
	return (this->target);
}
void	PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	this->checkExecutability(executor);
	std::cout << this->target << " has been pardoned by Zafod Beeblebrox." << std::endl;	
}
