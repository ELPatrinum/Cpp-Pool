/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:34:38 by muel-bak          #+#    #+#             */
/*   Updated: 2024/10/26 13:35:57 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
PmergeMe::PmergeMe(void){}
PmergeMe::PmergeMe(PmergeMe &other)
{
	if (this != &other)
	{
		this->vc = other.vc;
		this->dq = other.dq;
	}
}
PmergeMe &PmergeMe::operator=(PmergeMe &other)
{
	if (this != &other)
	{
		this->vc = other.vc;
		this->dq = other.dq;
	}
	return (*this);
}
PmergeMe::~PmergeMe(void){}

void PmergeMe::launch(std::string line)
{
	
}