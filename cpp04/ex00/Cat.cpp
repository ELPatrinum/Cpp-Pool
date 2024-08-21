/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:31:32 by muel-bak          #+#    #+#             */
/*   Updated: 2024/08/20 13:52:27 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	std::cout << "Cat Created" << std::endl;
}
Cat::~Cat()
{
	std::cout << "Cat Destroyed" << std::endl;
}
void Cat::makeSound()
{
	std::cout << "Meow!!" << std::endl;
}
