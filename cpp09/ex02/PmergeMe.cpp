/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:34:38 by muel-bak          #+#    #+#             */
/*   Updated: 2024/11/03 21:47:10 by muel-bak         ###   ########.fr       */
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
    char *c_line = new char[line.length() + 1];
    std::strcpy(c_line, line.c_str());
    
    char *c_element = std::strtok(c_line, " ");
    while (c_element)
    {
        std::string element(c_element);
        if (std::isdigit(element[0]))
        {
            container.push_back(std::atoi(element.c_str()));
        }
        else
        {
            delete[] c_line;
            throw std::runtime_error("Error: non-numeric input detected");
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
void PmergeMe::launch(std::string line)
{
	ft_add(line, vc);
	this->print_arr(vc, true);
	clock_t start = clock();
	FGSsort(vc, vc.begin(), vc.end() - 1);
	clock_t end = clock();
	this->print_arr(vc, false);
	double duration1 = double(end - start);
	ft_add(line, dq);
	start = clock();
	FGSsort(dq, dq.begin(), dq.end() - 1);
	end = clock();
	double duration2 = double(end - start);
	std::cout << "Time taken using [std::vector] : " << duration1 * 1000 << " ms" << std::endl;
	std::cout << "Time taken using [std::deque] : " << duration2 * 1000 << " ms" << std::endl;
}


// Function to insert element into sorted portion of the vector using binary search
void binary_insert(std::vector<int>& vec, int value, int end)
{
    std::vector<int>::iterator pos = std::lower_bound(vec.begin(), vec.begin() + end, value);
    vec.insert(pos, value);
    vec.erase(vec.begin() + end + 1); // Remove the redundant element at the end after insertion
}





// Recursive function to divide, sort, and merge vector in place
void recursive_sort(std::vector<int>& vec, int start, int end)
{
    if (start >= end)
        return;

    int mid = start + (end - start) / 2;

    // Divide the vector into two halves
    recursive_sort(vec, start, mid);
    recursive_sort(vec, mid + 1, end);

    // Temporary vector to hold the sorted merge of two halves
    std::vector<int> merged;

    // Merge two sorted halves into 'merged' using binary insertion
    for (int i = start; i <= mid; ++i)
        binary_insert(merged, vec[i], merged.size());
    for (int i = mid + 1; i <= end; ++i)
        binary_insert(merged, vec[i], merged.size());

    // Copy merged result back into the original vector
    for (int i = 0; i < merged.size(); ++i)
        vec[start + i] = merged[i];
}

// Wrapper function to sort the entire vector in place
void sort_vector(std::vector<int>& vec)
{
    if (vec.empty())
		return;
	int start, end;
	start = 0; end = vec.size() - 1;
    recursive_sort(vec, 0, vec.size() - 1);
}





// // Function to insert element into sorted vector using binary search
// void binary_insert(std::vector<int>& sorted_vec, int value)
// {
//     std::vector<int>::iterator pos = std::lower_bound(sorted_vec.begin(), sorted_vec.end(), value);
//     sorted_vec.insert(pos, value);
// }

// // Recursive function to divide, sort, and merge vector
// std::vector<int> recursive_sort(std::vector<int>& vec, int start, int end)
// {
//     if (start >= end)
//         return std::vector<int>(1, vec[start]);

//     int mid = start + (end - start) / 2;

//     // Divide the vector into two halves
//     std::vector<int> left = recursive_sort(vec, start, mid);
//     std::vector<int> right = recursive_sort(vec, mid + 1, end);

//     // Merge two sorted halves using binary insertion
//     std::vector<int> merged;
//     for (size_t i = 0; i < left.size(); ++i)
//         binary_insert(merged, left[i]);
//     for (size_t i = 0; i < right.size(); ++i)
//         binary_insert(merged, right[i]);

//     return (merged);
// }

// // Wrapper function to sort the entire vector
// std::vector<int> sort_vector(std::vector<int>& vec)
// {
//     if (vec.empty())
// 		return vec;
//     return recursive_sort(vec, 0, vec.size() - 1);
// }
