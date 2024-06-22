/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 05:09:02 by muel-bak          #+#    #+#             */
/*   Updated: 2024/06/22 11:09:10 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

bool	set_contact(Contact *contact)
{
	bool empty = false;
	
	std::string word[5];
	std::cout << "\033[1;35mEnter First_name\033[0;37m" << std::endl;
	std::cout << "=>"; std::getline(std::cin, word[0]);
	word[0] = trim_and_replace_tabs(word[0]); if(!word[0].compare("")){empty = true;}
	std::cout << "\033[1;35mEnter Last_name\033[0;37m" << std::endl;
	std::cout << "=>"; std::getline(std::cin, word[1]);
	word[1] = trim_and_replace_tabs(word[1]); if(!word[1].compare("")){empty = true;}
	std::cout << "\033[1;35mEnter Nickname\033[0;37m" << std::endl;
	std::cout << "=>"; std::getline(std::cin, word[2]);
	word[2] = trim_and_replace_tabs(word[2]); if(!word[2].compare("")){empty = true;}
	std::cout << "\033[1;35mEnter Phone_number\033[0;37m" << std::endl;
	std::cout << "=>"; std::getline(std::cin, word[3]);
	word[3] = trim_and_replace_for_numb(word[3]);  if(!word[3].compare("") || !is_all_digits(word[3])){empty = true;}
	std::cout << "\033[1;35mEnter Darkest_secret\033[0;37m" << std::endl;
	std::cout << "=>"; std::getline(std::cin, word[4]);
	word[4] = trim_and_replace_tabs(word[4]);  if(!word[4].compare("")){empty = true;}
	if (empty)
		return (false);
	contact->set_first_name(word[0]);
	contact->set_last_name(word[1]);
	contact->set_nickname(word[2]);
	contact->set_phone_number(word[3]);
	contact->set_darkest_secret(word[4]);
	return (true);
}

void	display_it(Phonebook phonebook)
{
	
	int i = 0;
	print_top();
    while (i < phonebook.count)
    {
        std::cout << "|" << std::setw(10) << i << "|"
                  << std::setw(10) << (phonebook.contact[i].get_first_name().length() > 10 ?
				  phonebook.contact[i].get_first_name().substr(0, 9) + "." :
				  phonebook.contact[i].get_first_name()) << "|"
                  << std::setw(10) << (phonebook.contact[i].get_last_name().length() > 10 ?
				  phonebook.contact[i].get_last_name().substr(0, 9) + "." :
				  phonebook.contact[i].get_last_name()) << "|"
                  << std::setw(10) << (phonebook.contact[i].get_nickname().length() > 10 ?
				  phonebook.contact[i].get_nickname().substr(0, 9) + "." :
				  phonebook.contact[i].get_nickname()) << "|" << std::endl;
		i++;
    }
	print_bot();
}

void	select_it(Phonebook phonebook)
{
	int			index;
	std::string	line;

	std::cout << "\033[1;35mSelect by Index :\033[0;37m" << std::endl;
	std::getline(std::cin, line);
	if (is_all_digits(line))
		index = std::atoi(line.c_str());
	else
	{
		std::cout << "\033[1;31mNo such an Index :\033[0;37m" <<  std::endl;
		return;
	}
	if (!phonebook.empty && index >= 0 && index <= phonebook.count)
	{
		std::cout << "First_name :" << phonebook.contact[index].get_first_name() << std::endl;
		std::cout << "Last_name :" << phonebook.contact[index].get_last_name() << std::endl;
		std::cout << "Nickname :" << phonebook.contact[index].get_nickname() << std::endl;
		std::cout << "Phone number :" << phonebook.contact[index].get_phone_number() << std::endl;
		std::cout << "Darkest secret :" << phonebook.contact[index].get_darkest_secret() << std::endl;
	}
	else
		std::cout << "\033[1;31mNo such an Index :\033[0;37m" <<  std::endl;
	return;
}


int	main()
{
	Phonebook phonebook;
	phonebook.ix = 0;
	phonebook.count = 0;
	phonebook.empty = true;
	std::string line;
	std::cout << "\033[1;33mWelcome. you can use the Phonebook by typing :" << std::endl;
	std::cout << "ADD, SEARH, EXIT\033[0;37m" << std::endl;
	while(1)
	{
		std::cout << "=>"; std::getline(std::cin, line);
		if (std::cin.eof())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max());
			continue;
		}
		if (!line.compare("ADD"))
		{
			if (set_contact(&(phonebook.contact[phonebook.ix])))
			{
				phonebook.empty = false;
				std::cout << "\033[1;32mDONE!\033[0;37m" << std::endl;
				phonebook.ix++;
				if (phonebook.count < 8)
					phonebook.count++;
				if (phonebook.ix >= 8)
					phonebook.ix = 0;	
			}
			else
				std::cout << "\033[1;31mERROR! INVALID FEILD" << std::endl << "make sure there's no empty feilds and the phone number is valid\033[0;37m" << std::endl;
		}
		else if (!line.compare("SEARCH"))
		{
			display_it(phonebook);
			select_it(phonebook);
		}
		else if (!line.compare("EXIT"))
			break;
	}
	return (0);
}
