/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 22:30:30 by muel-bak          #+#    #+#             */
/*   Updated: 2024/10/17 22:53:12 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base *generate(void)
{
	static bool seeded = false;
    if (!seeded)
	{
        std::srand(static_cast<unsigned int>(std::time(0)));
        seeded = true;
    }
    int randomValue = std::rand() % 3;
    switch (randomValue)
	{
        case 0: return new A();
        case 1: return new B();
        case 2: return new C();
        default: return nullptr;
    }
}


void identify(Base *p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
	else
        std::cout << "Unknown" << std::endl;
}

void identify(Base &p)
{
    try
	{
        A &a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A" << std::endl;
    } catch (std::bad_cast&) {}

    try
	{
        B &b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "B" << std::endl;
    } catch (std::bad_cast&) {}

    try
	{
        C &c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "C" << std::endl;
    } catch (std::bad_cast&) {}
}
