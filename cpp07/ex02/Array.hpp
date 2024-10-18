/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 01:05:17 by muel-bak          #+#    #+#             */
/*   Updated: 2024/10/18 01:50:50 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <stdexcept>
#include <memory>

template <typename T>
class Array
{
private:
    T	*data;
    unsigned int len;

public:
    Array() : data(nullptr), len(0) {}
    Array(unsigned int n) : len(n)
	{
        data = new T[len];
        for (unsigned int i = 0; i < len; ++i)
		{
            data[i] = T();
        }
    }
    Array(const Array &other) : len(other.len)
	{
        data = new T[len];
        for (unsigned int i = 0; i < len; ++i)
		{
            data[i] = other.data[i];
        }
    }
    Array& operator=(const Array &other)
	{
        if (this != &other)
		{
            delete[] data;
            len = other.len;
            data = new T[len];
            for (unsigned int i = 0; i < len; ++i)
			{
                data[i] = other.data[i];
            }
        }
        return (*this);
    }

    T& operator[](unsigned int index)
	{
        if (index >= len)
            throw std::out_of_range("Index out of bounds");
        return (data[index]);
    }

    const T& operator[](unsigned int index) const
	{
        if (index >= len)
            throw std::out_of_range("Index out of bounds");
        return (data[index]);
    }

    unsigned int size() const
	{
        return (len);
    }

    ~Array()
	{
        delete[] data;
    }
};

#endif
