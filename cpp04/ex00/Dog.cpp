/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:11:49 by muel-bak          #+#    #+#             */
/*   Updated: 2024/08/20 13:52:57 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	std::cout << "Dog Created" << std::endl;
}
Dog::~Dog()
{
	std::cout << "Dog Destroyed" << std::endl;
}
void Dog::makeSound()
{
	std::cout << "Bark!!" << std::endl;
}