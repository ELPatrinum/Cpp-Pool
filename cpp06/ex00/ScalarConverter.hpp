/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:17:24 by muel-bak          #+#    #+#             */
/*   Updated: 2024/10/17 16:14:44 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <climits>

class ScalarConverter
{
private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter& operator=(const ScalarConverter &other);
public:
		~ScalarConverter();
		static void convert(const std::string &str);
	
};

#endif