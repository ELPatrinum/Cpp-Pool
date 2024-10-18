/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 09:46:28 by muel-bak          #+#    #+#             */
/*   Updated: 2024/10/18 10:19:24 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "easyfind.hpp"

int main()
{
	try {
		std::vector<int> vec;
		vec.push_back(1);
		vec.push_back(2);
		vec.push_back(3);
		vec.push_back(4);
		vec.push_back(5);

		std::vector<int>::iterator it = easyfind(vec, 4);
		std::cout << "Found in vector: " << *it << std::endl;
		
		std::list<int> lst;
		lst.push_back(10);
		lst.push_back(20);
		lst.push_back(30);
		lst.push_back(40);
		lst.push_back(50);

		std::list<int>::iterator lit = easyfind(lst, 10);
		std::cout << "Found in list: " << *lit << std::endl;

		std::deque<int> deq;
		deq.push_back(100);
		deq.push_back(200);
		deq.push_back(300);
		deq.push_back(400);
		deq.push_back(500);

		std::deque<int>::iterator dit = easyfind(deq, 500);
		std::cout << "Found in deque: " << *dit << std::endl;

		it = easyfind(vec, 6);
	}
	catch (const NotFoundException &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
