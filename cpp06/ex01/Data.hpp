/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:09:26 by muel-bak          #+#    #+#             */
/*   Updated: 2024/10/17 17:50:44 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <string>

struct Data
{
    int id;
    std::string name;
public:
	Data();
	Data(int x, const std::string &str);
	Data(const Data &other);
	Data &operator=(const Data &other);

};

#endif
