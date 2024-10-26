/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:34:30 by muel-bak          #+#    #+#             */
/*   Updated: 2024/10/26 13:35:48 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
class PmergeMe
{
	std::vector<int> vc;
	std::deque<int> dq;
public:
	PmergeMe(void);
	PmergeMe(PmergeMe &other);
	PmergeMe &operator=(PmergeMe &other);
	~PmergeMe(void);
	void launch(std::string line);
};


#endif