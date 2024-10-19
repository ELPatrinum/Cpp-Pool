/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:05:21 by muel-bak          #+#    #+#             */
/*   Updated: 2024/10/19 15:41:15 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <iterator>
#include <limits>
#include <iostream>
#include <vector>
#include <stdexcept>

class Span
{
private:
    unsigned int maxSize;
    std::vector<int> nbrs;

public:

    Span(unsigned int N);
    ~Span();

    void addNumber(int nbr);
    int shortestSpan() const;
    int longestSpan() const;
    template <typename InputIterator>
    void addRange(InputIterator begin, InputIterator end);
};

template <typename InputIterator>
void Span::addRange(InputIterator begin, InputIterator end)
{
    if (std::distance(begin, end) + nbrs.size() > maxSize)
        throw std::out_of_range("Adding this range would exceed the Span's capacity.");
    nbrs.insert(nbrs.end(), begin, end);
}

#endif
