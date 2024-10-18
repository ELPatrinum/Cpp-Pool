/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 01:15:44 by muel-bak          #+#    #+#             */
/*   Updated: 2024/10/18 01:17:39 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
    try {
        Array<int> arr1;
        std::cout << "Size of arr1: " << arr1.size() << std::endl;

        Array<int> arr2(5);
        std::cout << "Size of arr2: " << arr2.size() << std::endl;

        for (unsigned int i = 0; i < arr2.size(); ++i)
		{
            arr2[i] = i + 1;
        }

        std::cout << "Elements in arr2: ";
        for (unsigned int i = 0; i < arr2.size(); ++i)
		{
            std::cout << arr2[i] << " ";
        }
        std::cout << std::endl;

        Array<int> arr3(arr2);
        std::cout << "Size of arr3 (copy of arr2): " << arr3.size() << std::endl;

        arr3[0] = 99;
        std::cout << "First element in arr2 after modifying arr3: " << arr2[0] << std::endl;

        Array<int> arr4;
        arr4 = arr2;
        std::cout << "First element in arr4 after assignment: " << arr4[0] << std::endl;

        try
		{
            std::cout << arr2[10] << std::endl;
        }
		catch (const std::out_of_range &e)
		{
            std::cout << "Exception caught: " << e.what() << std::endl;
        }

    }
	catch (const std::exception &e)
	{
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return (0);
}