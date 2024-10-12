/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:15:32 by muel-bak          #+#    #+#             */
/*   Updated: 2024/10/08 19:42:37 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


int main()
{
    try {
        Bureaucrat Kayle("Kayle", 1);
        Bureaucrat Morgana("Morgana", 150);

        std::cout << "Just created two bureaucrat gods!" << std::endl;
        std::cout << Kayle << std::endl;
        std::cout << Morgana << std::endl;

        std::cout << "\nTrying to create Graves with grade 0..." << std::endl;
        try {
            Bureaucrat Graves("Graves", 0);
        } catch (const std::exception& e) {
            std::cout << "Cannot create Graves!" << std::endl;
            std::cout << "Exception: " << e.what() << std::endl;
        }

        std::cout << "\nTrying to create Jax with grade 159..." << std::endl;
        try {
            Bureaucrat Jax("Jax", 159);
        } catch (const std::exception& e) {
            std::cout << "Cannot create Jax!" << std::endl;
            std::cout << "Exception: " << e.what() << std::endl;
        }


		std::cout << "\nTrying to create Lulu with grade 50..." << std::endl;
        try {
            Bureaucrat Lulu("Lulu", 50);
			Lulu.incGrade();
			std::cout << "Lulu promoted! " << Lulu << std::endl;
			Lulu.decGrade();
			std::cout << "Lulu demoted! New state: " << Lulu << std::endl;
			Bureaucrat Nami(Lulu);
			std::cout << Nami << std::endl;
			Bureaucrat Swain = Nami;
			std::cout << Swain << std::endl;
        } catch (const std::exception& e) {
            std::cout << "Cannot create Lulu!" << std::endl;
            std::cout << "Exception: " << e.what() << std::endl;
        }

        std::cout << "\nTrying to promote Kayle..." << std::endl;
        try {
            Kayle.incGrade();
            std::cout << "Kayle promoted! New state: " << Kayle << std::endl;
        } catch (const std::exception& e) {
            std::cout << "Cannot increment the grade of Kayle!" << std::endl;
            std::cout << "Exception: " << e.what() << std::endl;
        }

        std::cout << "\nTrying to demote Morgana..." << std::endl;
        try {
            Morgana.decGrade();
            std::cout << "Morgana demoted! New state: " << Morgana << std::endl;
        } catch (const std::exception& e) {
            std::cout << "Cannot decrement the grade of Morgana!" << std::endl;
            std::cout << "Exception: " << e.what() << std::endl;
        }

    } catch (const std::exception& e)
	{
        std::cout << "An unexpected exception occurred: " << e.what() << std::endl;
    }

    return (0);
}
