/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:34:30 by muel-bak          #+#    #+#             */
/*   Updated: 2024/10/29 12:02:31 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

# include <cstring>
# include <cstdlib>
# include <stdexcept>
# include <iostream>
# include <vector>
# include <deque>
class PmergeMe
{
	std::vector<int> vc;
	std::deque<int> dq;
	template <typename T>
	void	FGSsort(T& container, typename T::iterator left, typename T::iterator right);
	template <typename T>
	void	ft_merge(T& container, typename T::iterator left, typename T::iterator mid, typename T::iterator right);
	template <typename T>
	void	ft_add(const std::string& line, T& container);
	template <typename T>
	void	print_arr(T &arry, bool check);
public:
	PmergeMe(void);
	PmergeMe(PmergeMe &other);
	PmergeMe &operator=(PmergeMe &other);
	~PmergeMe(void);
	void launch(char **av, int ac);
	std::string mergeStrings(char** strings, int count);
};


#endif