/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 02:41:56 by muel-bak          #+#    #+#             */
/*   Updated: 2024/10/12 13:35:27 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "AForm.hpp"
#include <ctime>
class RobotomyRequestForm : public AForm
{
	private:
		const std::string	target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &other);
		using			AForm::operator=;
		~RobotomyRequestForm();
		const std::string &getTarget() const;
		virtual void	execute(const Bureaucrat &executor) const;
};
#endif
