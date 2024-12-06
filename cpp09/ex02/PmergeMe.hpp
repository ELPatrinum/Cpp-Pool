/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:34:30 by muel-bak          #+#    #+#             */
/*   Updated: 2024/11/21 03:42:01 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

# include <cstring>
# include <cstdlib>
# include <stdexcept>
# include <iostream>
# include <algorithm>
# include <sys/time.h> 
# include <vector>
# include <deque>
# include <cmath>

class PmergeMe
{
	std::vector<int> vc;
	std::deque<int> dq;
	template <typename T>
	void	FGSsort(T &container);
	template <typename T>
	void	ft_add(const std::string &line, T &container);
	template <typename T>
	void	print_arr(T &arry);
	template <typename T>
	void devide_sort(T &container, int start, int end);
public:
	PmergeMe(void);
	PmergeMe(PmergeMe &other);
	PmergeMe &operator=(PmergeMe &other);
	~PmergeMe(void);
	void launch(std::string line);
	std::string mergeStrings(char **strings, int count);
};

#endif