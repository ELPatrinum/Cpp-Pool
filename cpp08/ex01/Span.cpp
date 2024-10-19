/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:07:00 by muel-bak          #+#    #+#             */
/*   Updated: 2024/10/19 15:41:38 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) : maxSize(N)
{
    
}

Span::~Span()
{
    
}

void Span::addNumber(int nbr)
{
    if (nbrs.size() >= maxSize)
    {
        throw std::out_of_range("Span is Full");
    }
    nbrs.push_back(nbr);
}

int Span::shortestSpan() const
{
    if (nbrs.size() <= 1)
        throw std::logic_error("No span can be found..!");

    std::vector<int> sorted(nbrs);
    std::sort(sorted.begin(), sorted.end());

    int minSpan = std::numeric_limits<int>::max();
    std::size_t i = 1;
    while ( i < sorted.size())
    {
        int diff = sorted[i] - sorted[i - 1];
        if (diff < minSpan)
            minSpan = diff;
        ++i;
    }
    return (minSpan);
}

int Span::longestSpan() const
{
    if (nbrs.size() <= 1)
        throw std::logic_error("No span can be found..!");

    std::vector<int>::const_iterator minIt = std::min_element(nbrs.begin(), nbrs.end());
    std::vector<int>::const_iterator maxIt = std::max_element(nbrs.begin(), nbrs.end());

    return (*maxIt - *minIt);
}


