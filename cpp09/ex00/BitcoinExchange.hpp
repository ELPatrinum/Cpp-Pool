/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 13:08:22 by muel-bak          #+#    #+#             */
/*   Updated: 2024/10/21 17:02:27 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
# include <iostream>
# include <fstream>
# include <string>
# include <map>
# include <stdexcept>
# include <cstring>
# include <cstdlib>
# include <exception>


class BitcoinExchange
{
    std::string filename;
    std::string dataname;
    std::map<std::string, float> data;
public:
	BitcoinExchange(void);
    BitcoinExchange(const BitcoinExchange &other);
    ~BitcoinExchange();
    BitcoinExchange &operator=(const BitcoinExchange &other);

	void isValidKey(const std::string &date);
	std::string trimSpaces(const std::string& str);
	void isValidValue(const std::string &value);
	void	check_find(std::string file);
	std::string findDate(const std::string &date);
	std::string ft_itoa(int num);
};


#endif