/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:34:38 by muel-bak          #+#    #+#             */
/*   Updated: 2024/10/28 17:18:01 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
PmergeMe::PmergeMe(void){}
PmergeMe::PmergeMe(PmergeMe &other)
{
	if (this != &other)
	{
		this->vc = other.vc;
		this->dq = other.dq;
	}
}
PmergeMe &PmergeMe::operator=(PmergeMe &other)
{
	if (this != &other)
	{
		this->vc = other.vc;
		this->dq = other.dq;
	}
	return (*this);
}
PmergeMe::~PmergeMe(void){}

template <typename T>
void PmergeMe::ft_merge(T &container, typename T::iterator left, typename T::iterator mid, typename T::iterator right)
{
	std::vector<typename T::value_type> leftVec(left, mid + 1);
	std::vector<typename T::value_type> rightVec(mid + 1, right + 1);
	(void)container;

	size_t i = 0, j = 0;
	typename T::iterator k = left;

	while (i < leftVec.size() && j < rightVec.size())
	{
		if (leftVec[i] <= rightVec[j])
			*k++ = leftVec[i++];
		else
			*k++ = rightVec[j++];
	}

	while (i < leftVec.size())
		*k++ = leftVec[i++];

	while (j < rightVec.size())
		*k++ = rightVec[j++];
}

template <typename T>
void PmergeMe::FGSsort(T &container, typename T::iterator left, typename T::iterator right)
{
	if (left < right)
	{
		typename T::iterator mid = left + std::distance(left, right) / 2;
		FGSsort(container, left, mid);
		FGSsort(container, mid + 1, right);
		ft_merge(container, left, mid, right);
	}
}
template <typename T>
void PmergeMe::ft_add(const std::string &line, T &container)
{
	char    *c_line = const_cast<char*>(line.c_str());
	char	*c_element = strtok(c_line, " ");
	std::string element(c_element);
	while(c_element)
	{
		if (std::isdigit(element[0]))
			container.push_back(atoi(element.c_str()));
		else
		{
			throw std::runtime_error("Error");
		}
		c_element = strtok(NULL, " ");
		if (c_element)
			element = c_element;
	}
}
std::string PmergeMe::mergeStrings(char** strings, int count)
{
    std::string result;

    for (int i = 0; i < count; ++i)
	{
        if (i > 0)
            result += " ";
        result += strings[i];
    }
    return (result);
}
template <typename T>
void	PmergeMe::print_arr(T &arry, bool check)
{
	if (check)
		std::cout << "Before:" << " ";
	else
		std::cout << "After:" << " ";
	for (size_t i = 0; i < arry.size(); ++i)
        std::cout << arry[i] << " ";
	std::cout << std::endl;
}
void PmergeMe::launch(char **av, int ac)
{
	std::string line = mergeStrings(av + 1, ac -1);
	ft_add(line, vc);
	this->print_arr(vc, true);
	clock_t start = clock();
	FGSsort(vc, vc.begin(), vc.end() - 1);
	clock_t end = clock();
	this->print_arr(vc, false);
	double duration1 = double(end - start);
	line = mergeStrings(av + 1, ac -1);
	ft_add(line, dq);
	start = clock();
	FGSsort(dq, dq.begin(), dq.end() - 1);
	end = clock();
	double duration2 = double(end - start);
	std::cout << "Time taken using [std::vector] : " << duration1 * 1000 << " ms" << std::endl;
	std::cout << "Time taken using [std::deque] : " << duration2 * 1000 << " ms" << std::endl;
}
