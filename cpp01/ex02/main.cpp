/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 20:13:21 by muel-bak          #+#    #+#             */
/*   Updated: 2024/06/10 20:29:17 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

int main ()
{
	std::string line = "HI THIS IS BRAIN";
	std::string *ptr = &line;
	std::string &ref = line;
	std::cout << "The memory address of the string variable : " << &line << std::endl;
	std::cout << "The memory address held by stringPTR      : " << ptr << std::endl;
	std::cout << "The memory address held by stringREF      : " << &ref << std::endl;
	std::cout << "The value of the string variable  : " << line << std::endl;
	std::cout << "The value pointed to by stringPTR : " << *ptr << std::endl;
	std::cout << "The value pointed to by stringREF : " << ref << std::endl;
	return (0);
}
