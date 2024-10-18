/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 00:22:50 by muel-bak          #+#    #+#             */
/*   Updated: 2024/10/18 00:29:37 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>

template <typename T, typename Func>
void iter(T *array, size_t length, Func func)
{
	size_t i = 0;
    while (i < length)
	{
        func(array[i++]);
    }
}

#endif
