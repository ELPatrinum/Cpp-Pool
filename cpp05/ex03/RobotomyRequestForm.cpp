/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 02:42:03 by muel-bak          #+#    #+#             */
/*   Updated: 2024/10/12 12:24:49 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() 
        : AForm("RobotomyrequestForm", 72, 45), target("")
{
	
}
RobotomyRequestForm::RobotomyRequestForm(const std::string &target) 
        : AForm("RobotomyrequestForm", 72, 45), target(target)
{
	
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) 
        : AForm("RobotomyrequestForm", 72, 45), target(other.getTarget())
{
	
}
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << this->target << " is Destroyed!" << std::endl;
}
const std::string&	RobotomyRequestForm::getTarget() const
{
	return (this->target);
}

void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	this->checkExecutability(executor);
	std::cout << "Drilling noises!!" << std::endl;
	static int seeded = 0;
    if (seeded == 100) {
        seeded = 0;
    }
    int randomValue = seeded % 2;
	seeded++;
	if (!randomValue)
	{
		std::cout << this->target;
		std::cout << " robotomized successfully!" << std::endl;
	}
	else
		std::cout << "The robotomization on " << this->target << " failed!" << std::endl;
}


// void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
// {
// 	this->checkExecutability(executor);
// 	std::cout << "Drilling noises!!" << std::endl;
// 	static bool seeded = false;
//     if (!seeded) {
//         std::srand(static_cast<unsigned int>(std::time(0)));
//         seeded = true;
//     }
//     int randomValue = std::rand() % 2;
// 	if (!randomValue)
// 	{
// 		std::cout << this->target;
// 		std::cout << " robotomized successfully!" << std::endl;
// 	}
// 	else
// 		std::cout << "The robotomization on " << this->target << " failed!" << std::endl;
// }