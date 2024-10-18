/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 09:48:55 by muel-bak          #+#    #+#             */
/*   Updated: 2024/10/18 10:09:50 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <iterator>
#include <exception>
#include <deque>
#include <vector>
#include <list>

class NotFoundException : public std::exception
{
public:
	const char* what() const throw()
	{
		return "No such Element in the container.";
	}
};

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
	typename T::iterator x = std::find(container.begin(), container.end(), value);

	if (x == container.end())
		throw NotFoundException();
	return (x);
}

#endif

