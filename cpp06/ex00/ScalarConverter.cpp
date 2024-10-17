/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:31:41 by muel-bak          #+#    #+#             */
/*   Updated: 2024/10/17 19:21:21 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	
};

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	*this = other;
};

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return (*this);
};
ScalarConverter::~ScalarConverter()
{
	
};

void ScalarConverter::convert(const std::string &str)
{
    std::string specialCase[6] = {"-inff", "+inff", "nanf","-inf", "+inf", "nan"};
	std::string _char = "";
	int _int = 0;
	float _float = 0;
	double _double = 0;

	if (str.size() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]))
	{
		_char = str[0];
		std::cout << "char: " << _char << std::endl;
		std::cout << "int: " << static_cast<int>(_char[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(_char[0]) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(_char[0]) << ".0" << std::endl;
		return;
	}
	_int = std::atoi(str.c_str());
	if(str.size() > 2 && _int == -1)
		std::cout << "\033[1;31mAn overflow happened in the int value!!!\033[0;37m" << std::endl;
	if (str[str.length() - 1] != 'f')
	{
		_double = std::atof(str.c_str());
		_float = static_cast<float>(_double);
	}
	else
	{
		_float = std::atof(str.c_str());
		_double = static_cast<double>(_float);
	}

	int i = 0;
	while (i < 6)
	{
		if (str == specialCase[i])
		{
			_char = "imposible"; break;
		}
		++i;
	}
	if (!_char[0] && std::isprint(_int))
	{
		_char = "'";
		_char += static_cast<char>(_int);
		_char += "'";
		if (!_char[0])
			_char = "Non displayable";
	}
	std::cout << "char: " << _char << std::endl;
	if (_char == "imposible" || (str.size() > 2 && _int == -1))
	{
		std::cout << "int: imposible" << std::endl;
	}
	else
	{
		std::cout << "int: " << _int << std::endl;
	}

	if (_char == "imposible" && _float == 0)
	{
		std::cout << "float: imposible" << std::endl;
		std::cout << "double: imposible" << std::endl;
	}
	else
	{
		if (_char != "imposible" && _float - static_cast<int>(_float) == 0)
		{
			std::cout << "float: " << _float << ".0f" << std::endl;
			std::cout << "double: " << _double << ".0" << std::endl;
		}
		else
		{
			std::cout << "float: " << _float << "f" << std::endl;
			std::cout << "double: " << _double << std::endl;
		}
	}
}
