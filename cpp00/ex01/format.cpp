/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 12:43:44 by muel-bak          #+#    #+#             */
/*   Updated: 2024/09/11 20:39:00 by muel-bak         ###   ########.fr       */
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

bool is_all_digits(const std::string &str)
{
    if (str.empty())
        return (false);
    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it)
	{
        if (!::isdigit(*it) && !::isspace(*it) && *it != '+')
            return (false); 
    }
    return (true);
}

std::string trim_and_replace_for_numb(const std::string &line)
{
    size_t start = 0;
    size_t end = line.length();

    while (start < end && (std::isspace(line[start]) || line[start] == '\t'))
        ++start;
    while (end > start && (std::isspace(line[end - 1]) || line[end - 1] == '\t'))
        --end;
    std::string result;
    for (size_t i = start; i < end; ++i)
	{
        if (line[i] == '\t' || line[i] == ' ')
            continue;
        else
            result += line[i];
    }

    return result;
}


std::string remove_non_printable(const std::string& input)
{
    std::string result;
    for (std::string::size_type i = 0; i < input.size(); ++i)
    {
        char ch = input[i];
        if (std::isprint(static_cast<unsigned char>(ch)))
            result += ch;
    }
    return result;
}

std::string trim_and_replace_tabs(const std::string &line)
{
    size_t start = 0;
    size_t end = line.length();

    while (start < end && (std::isspace(line[start]) || line[start] == '\t'))
        ++start;
    while (end > start && (std::isspace(line[end - 1]) || line[end - 1] == '\t'))
        --end;
    std::string result;
    for (size_t i = start; i < end; ++i)
	{
        if (line[i] == '\t')
            result += ' ';
        else
            result += line[i];
    }

    return result;
}
