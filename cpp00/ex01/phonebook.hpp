/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 05:23:18 by muel-bak          #+#    #+#             */
/*   Updated: 2024/09/11 20:34:24 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <cctype>
# include <cstdio>
# include <limits>
# include <iomanip>

class Contact
{
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;
public :
	std::string	get_first_name();
	std::string	get_last_name();
	std::string	get_nickname();
	std::string	get_phone_number();
	std::string	get_darkest_secret();
	void	set_first_name(std::string line);
	void	set_last_name(std::string line);
	void	set_nickname(std::string line);
	void	set_phone_number(std::string line);
	void	set_darkest_secret(std::string line);
};

class Phonebook
{
	
public :

	Contact	contact[8];
	int		ix;
	int		count;
	bool	empty;
};

void		print_top(void);
void		print_bot();
bool		is_all_digits(const std::string &str);
std::string	trim_and_replace_tabs(const std::string &line);
std::string trim_and_replace_for_numb(const std::string &line);
std::string remove_non_printable(const std::string& input);

#endif