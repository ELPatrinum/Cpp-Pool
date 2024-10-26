/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:15:17 by muel-bak          #+#    #+#             */
/*   Updated: 2024/10/26 13:29:26 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
	f[0] = &RPN::add;
	f[1] = &RPN::sub;
	f[2] = &RPN::mul;
	f[3] = &RPN::div;
};
RPN::RPN(RPN &other)
{
	if(this != &other)
		this->_stack = other._stack;
};
RPN &RPN::operator=(RPN &other)
{
	if(this != &other)
		this->_stack = other._stack;
	return (*this);
};
RPN::~RPN(){};

int RPN::get_op(std::string line)
{
	std::string arr[4] = {"+", "-", "*", "/"};
	int i = 0;
	while(line != arr[i] && i < 5)
		i++;
		return (i);
}

int RPN::add(int a, int b)
{
    return (a + b);
}

int RPN::sub(int a, int b)
{
    return (a - b);
}

int RPN::mul(int a, int b)
{
    return (a * b);
}

int RPN::div(int a, int b)
{
	if (b == 0)
    	throw std::runtime_error("Division by zero");
    return (a / b);
}
std::string RPN::ft_itoa(int num)
{
    std::string str = "";
    if (num == 0)
        return ("0");
    bool isNegative = false;
    if (num < 0)
	{
        isNegative = true;
        num = -num;
    }
    while (num > 0)
	{
        str = char(num % 10 + '0') + str;
        num /= 10;
    }
    if (isNegative)
        str = "-" + str;
    return (str);
}
void RPN::calculate(std::string &line)
{
	char    *c_line = const_cast<char*>(line.c_str());
	char	*c_element = strtok(c_line, " ");
	std::string element(c_element);
	while(c_element)
	{
		if (std::isdigit(element[0]))
			_stack.push(element);
		else
		{
			if (get_op(element) > 4)
				throw std::runtime_error("Error");
			if (_stack.size() > 1)
			{
				int b = atoi(_stack.top().c_str()); _stack.pop();
				int a = atoi(_stack.top().c_str()); _stack.pop();
				int result = (this->*f[get_op(element)])(a, b);
				_stack.push(ft_itoa(result));
			}
		}
		c_element = strtok(NULL, " ");
		if (c_element)
			element = c_element;
	}
	if (_stack.size() == 1)
		std::cout << _stack.top() << std::endl;
	else
		throw std::runtime_error("Error");
}
