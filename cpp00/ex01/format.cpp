/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 12:43:44 by muel-bak          #+#    #+#             */
/*   Updated: 2024/06/01 13:46:55 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void	print_top(void)
{
	std::cout << "|----------|"
			  << "----------|"
			  << "----------|"
			  << "----------|" << std::endl
			  << "|" << std::setw(10) << "Index" << "|"
			  << std::setw(10) << "First Name" << "|"
			  << std::setw(10) << "Last Name" << "|"
			  << std::setw(10) << "Nickname" << "|" << std::endl
			  << "|----------|"
			  << "----------|"
			  << "----------|"
			  << "----------|" << std::endl;
}

void	print_bot()
{
	std::cout << "|----------|"
			  << "----------|"
			  << "----------|"
			  << "----------|" << std::endl;
}

bool	is_all_digits(const std::string& str)
{
    return (!str.empty() && std::all_of(str.begin(), str.end(), ::isdigit));
}
