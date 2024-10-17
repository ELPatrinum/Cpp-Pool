/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:13:58 by muel-bak          #+#    #+#             */
/*   Updated: 2024/10/17 17:19:57 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(): id(10), name("randome"){};
Data::Data(int x, const std::string &str): id(x), name(str){};
Data::Data(const Data &other): id(other.id), name(other.name){};
Data &Data::operator=(const Data &other)
{
	if (this != &other)
	{
		id = other.id;
		name = other.name;
    }
    return (*this);
}
