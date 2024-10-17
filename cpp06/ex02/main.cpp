/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 22:30:57 by muel-bak          #+#    #+#             */
/*   Updated: 2024/10/17 22:54:26 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


int main()
{
    Base *obj = generate();
    
    std::cout << "Identifying using pointer:" << std::endl;
    identify(obj);

    std::cout << "Identifying using reference:" << std::endl;
    identify(*obj);
	
    delete obj;
    return (0);
}