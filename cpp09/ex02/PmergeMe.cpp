/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:34:38 by muel-bak          #+#    #+#             */
/*   Updated: 2024/11/28 09:29:02 by muel-bak         ###   ########.fr       */
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

std::vector<int> generateJacobsthal(int end)
{
    std::vector<int> jacobsthalSeq;
    int j0 = 0, j1 = 1;

    if (j0 <= end) jacobsthalSeq.push_back(j0);
    if (j1 <= end) jacobsthalSeq.push_back(j1);

    while (true) {
        int jn = j1 + 2 * j0;
        if (jn > end) break;
        jacobsthalSeq.push_back(jn);
        j0 = j1;
        j1 = jn;
    }

    std::vector<int> result;
    int previousJacob = 1;
    for (size_t i = 1; i < jacobsthalSeq.size(); ++i)
	{
        int currentJacob = jacobsthalSeq[i];
        result.push_back(currentJacob);
        for (int j = currentJacob - 1; j > previousJacob; --j)
            result.push_back(j);
        previousJacob = currentJacob;
		
    }
	std::vector<int>::iterator maxElement = std::max_element(result.begin(), result.end());
	for (int i = *maxElement + 1; i < end; i++)
		result.push_back(i);
	if (!result.empty())
		result[0] = 0;
	if (result[result.size() - 1] != end)
		result.push_back(end);
    return (result);
}

template <typename T>
void binary_insert(T &container, int value, int end)
{
    typename T::iterator pos = std::lower_bound(container.begin(), container.begin() + end, value);
    container.insert(pos, value);
}

template <typename T>
void PmergeMe::devide_sort(T &container, int start, int end)
{
    if (start >= end)
        return;
	T extra;
	if (container.size() % 2 != 0)
	{
		extra.push_back(container[end]);
		container.erase(container.begin() + end);
		end-=1;
	}
    int i = start;
    while ((i + 1) <= end)
	{
        if (container[i] < container[i + 1])
            std::swap(container[i], container[i + 1]);
        i+=2;
    }
	i = 0;

	int maxIndex = end - (end % 2);
	while (true) {
		bool swapped = false;
		for (int i = 0; i + 2 <= maxIndex; i += 2)
		{
			if (container[i] > container[i + 2])
			{
				std::swap(container[i], container[i + 2]);
				std::swap(container[i + 1], container[i + 3]);
				swapped = true;
			}
		}
		if (!swapped)
			break;
	}
    T tmp;
    for (int i = 1; i <= end; i += 2)
        tmp.push_back(container[i]);

	if (!extra.empty())
	{
		 tmp.push_back(extra[0]);
	}

    for (int i = end; i >= start; i -= 2)
        container.erase(container.begin() + i);
	std::vector<int> Jc = generateJacobsthal(tmp.size() - 1);
    for (size_t i = 0; i < tmp.size(); ++i)
        binary_insert(container, tmp[Jc[i]], container.size());
}

template <typename T>
void PmergeMe::FGSsort(T &container)
{
	if (container.empty())
		return;
	devide_sort(container, 0, container.size() - 1);
}

template <typename T>
void	PmergeMe::print_arr(T &arry)
{
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
    std::cout << "Before:" << " "; this->print_arr(vc);
    long start = get_time_in_microseconds();
    FGSsort(vc);
    long end = get_time_in_microseconds();
    double duration1 = (end - start) / 1000.0;
    std::cout << "After:" << " "; this->print_arr(vc);
    ft_add(line, dq);
    start = get_time_in_microseconds();
    FGSsort(dq);
    end = get_time_in_microseconds();
    double duration2 = (end - start) / 1000.0;
    std::cout << "Time taken using [std::vector] : " << duration1 << " ms" << std::endl;
    std::cout << "Time taken using [std::deque ] : " << duration2 << " ms" << std::endl;
}
