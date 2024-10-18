/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 00:24:56 by muel-bak          #+#    #+#             */
/*   Updated: 2024/10/18 00:30:05 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "iter.hpp"

void print(int x)
{
    std::cout << x << " ";
}

void increment(int &x)
{
    x += 1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    size_t length = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: ";
    iter(arr, length, print);
    std::cout << std::endl;

    std::cout << "Incrementing array elements..." << std::endl;
    iter(arr, length, increment);

    std::cout << "Updated array: ";
    iter(arr, length, print);
    std::cout << std::endl;

    return 0;
}
