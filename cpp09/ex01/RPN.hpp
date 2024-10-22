/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:14:30 by muel-bak          #+#    #+#             */
/*   Updated: 2024/10/22 00:27:03 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP
#include <iostream>
#include <stack>

class RPN
{
	std::stack<std::string> _stack;
	int	get_op(std::string line);
	int add(int a, int b);
    int sub(int a, int b);
    int mul(int a, int b);
    int div(int a, int b);
	std::string ft_itoa(int num);
	typedef int (RPN::*func)(int, int);
	 func f[4];
public:
	RPN();
	RPN(RPN &other);
	RPN &operator=(RPN &other);
	~RPN();
	void calculate(std::string &line);
};

#endif