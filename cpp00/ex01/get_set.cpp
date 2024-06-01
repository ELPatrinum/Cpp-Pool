/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_set.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 12:22:45 by muel-bak          #+#    #+#             */
/*   Updated: 2024/06/01 12:23:09 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

std::string	Contact::get_first_name()
{
	return (first_name);
}
std::string	Contact::get_last_name()
{
	return (last_name);
}
std::string	Contact::get_nickname()
{
	return (nickname);
}
std::string	Contact::get_phone_number()
{
	return (phone_number);
}
std::string	Contact::get_darkest_secret()
{
	return (darkest_secret);
}
void	Contact::set_first_name(std::string line)
{
	first_name = line;
}
void	Contact::set_last_name(std::string line)
{
	last_name = line;
}
void	Contact::set_nickname(std::string line)
{
	nickname = line;
}
void	Contact::set_phone_number(std::string line)
{
	phone_number = line;
}
void	Contact::set_darkest_secret(std::string line)
{
	darkest_secret = line;
}
