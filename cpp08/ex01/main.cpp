/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:16:50 by muel-bak          #+#    #+#             */
/*   Updated: 2024/10/19 16:03:05 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
    std::cout << "Test Case 1: Basic Functionality" << std::endl;
    try
    {

        Span sp(5);
        sp.addNumber(5);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        // sp.addNumber(19);

        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

        Span largeSpan(10000);
        std::vector<int> largeNumbers;
        srand(time(0));
        for (int i = 0; i < 10000; ++i)
        {
            largeNumbers.push_back(rand() % 1000000);
        }
        largeSpan.addRange(largeNumbers.begin(), largeNumbers.end());

        std::cout << "\nTest Case 2: Large Input (10,000 Elements)" << std::endl;
        std::cout << "Shortest Span: " << largeSpan.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << largeSpan.longestSpan() << std::endl;


        std::cout << "\nTest Case 3: Adding Beyond Capacity" << std::endl;
        try
        {
            Span smallSpan(3);
            smallSpan.addNumber(1);
            smallSpan.addNumber(2);
            smallSpan.addNumber(3);
            smallSpan.addNumber(4);
        }
        catch (const std::exception &e)
        {
            std::cout << "Exception: " << e.what() << std::endl;
        }

        std::cout << "\nTest Case 4: Finding Spans with One Element" << std::endl;
        try
        {
            Span singleElementSpan(1);
            singleElementSpan.addNumber(42);
            std::cout << "Shortest Span: " << singleElementSpan.shortestSpan() << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << "Exception: " << e.what() << std::endl;
        }

        std::cout << "\nTest Case 5: Empty Span" << std::endl;
        try
        {
            Span emptySpan(10);
            std::cout << "Longest Span: " << emptySpan.longestSpan() << std::endl;
        } catch (const std::exception &e)
        {
            std::cout << "Exception: " << e.what() << std::endl;
        }

    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return (0);
}
