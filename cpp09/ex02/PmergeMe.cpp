/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:34:38 by muel-bak          #+#    #+#             */
/*   Updated: 2024/11/04 11:49:11 by muel-bak         ###   ########.fr       */
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
void PmergeMe::ft_add(const std::string &line, T &container)
{
	char *c_line = new char[line.length() + 1];
	std::strcpy(c_line, line.c_str());

	char *c_element = std::strtok(c_line, " ");
	while (c_element)
	{
		std::string element(c_element);
		if (std::isdigit(element[0]))
			container.push_back(std::atoi(element.c_str()));
		else
		{
			delete[] c_line;
			throw std::runtime_error("Error: non-numeric or non-positive input detected");
		}
		c_element = std::strtok(NULL, " ");
	}

	delete[] c_line;
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
void binary_insert(T &container, int value, int end)
{
	typename T::iterator pos = std::lower_bound(container.begin(), container.begin() + end, value);
	container.insert(pos, value);
}

template <typename T>
void devide_sort(T &container, int start, int end)
{
	if (start >= end)
		return;

	int mid = start + (end - start) / 2;

	devide_sort(container, start, mid);
	devide_sort(container, mid + 1, end);

	// Temporary container to hold the sorted merge of two halves
	T merged;

	// Merge two sorted halves into 'merged' using binary insertion
	for (int i = start; i <= mid; ++i)
		binary_insert(merged, container[i], merged.size());
	for (int i = mid + 1; i <= end; ++i)
		binary_insert(merged, container[i], merged.size());

	// Copy merged result back into the original container
	for (size_t i = 0; i < merged.size(); ++i)
		container[start + i] = merged[i];
}

template <typename T>
void PmergeMe::FGSsort(T &container)
{
	if (container.empty())
		return;
	devide_sort(container, 0, container.size() - 1);
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

long get_time_in_microseconds()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000000L + tv.tv_usec);
}
void PmergeMe::launch(std::string line)
{
	ft_add(line, vc);
    this->print_arr(vc, true);

    long start = get_time_in_microseconds();
    FGSsort(vc);
    long end = get_time_in_microseconds();
    double duration1 = (end - start) / 1000.0;
    this->print_arr(vc, false);
    ft_add(line, dq);
    start = get_time_in_microseconds();
    FGSsort(dq);
    end = get_time_in_microseconds();
    double duration2 = (end - start) / 1000.0;
    
    std::cout << "Time taken using [std::vector] : " << duration1 << " ms" << std::endl;
    std::cout << "Time taken using [std::deque ]  : " << duration2 << " ms" << std::endl;
}


// template <typename T>
// void PmergeMe::ft_merge(T &container, typename T::iterator left, typename T::iterator mid, typename T::iterator right)
// {
// 	std::vector<typename T::value_type> leftVec(left, mid + 1);
// 	std::vector<typename T::value_type> rightVec(mid + 1, right + 1);
// 	(void)container;

// 	size_t i = 0, j = 0;
// 	typename T::iterator k = left;

// 	while (i < leftVec.size() && j < rightVec.size())
// 	{
// 		if (leftVec[i] <= rightVec[j])
// 			*k++ = leftVec[i++];
// 		else
// 			*k++ = rightVec[j++];
// 	}

// 	while (i < leftVec.size())
// 		*k++ = leftVec[i++];

// 	while (j < rightVec.size())
// 		*k++ = rightVec[j++];
// }

// template <typename T>
// void PmergeMe::FGSsort(T &container, typename T::iterator left, typename T::iterator right)
// {
// 	if (left < right)
// 	{
// 		typename T::iterator mid = left + std::distance(left, right) / 2;
// 		FGSsort(container, left, mid);
// 		FGSsort(container, mid + 1, right);
// 		ft_merge(container, left, mid, right);
// 	}
// }