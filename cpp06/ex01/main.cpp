/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:00:04 by muel-bak          #+#    #+#             */
/*   Updated: 2024/10/17 17:54:29 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"

int main()
{
    Data* originalData = new Data(1, "Test Name");

    uintptr_t serializedData = Serializer::serialize(originalData);

    Data* deserializedData = Serializer::deserialize(serializedData);

    if (originalData == deserializedData)
	{
        std::cout << "Serialization and Deserialization successful!" << std::endl;
        std::cout << "ID: " << deserializedData->id << ", Name: " << deserializedData->name << std::endl;
    }
	else
	{
        std::cout << "Serialization and Deserialization failed!" << std::endl;
    }

    delete originalData;

    return (0);
}
