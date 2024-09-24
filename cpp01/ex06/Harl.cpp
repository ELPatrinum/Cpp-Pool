/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:30:19 by muel-bak          #+#    #+#             */
/*   Updated: 2024/09/24 16:59:43 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}
void    Harl::Debug( void )
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger."<< std::endl << "I really do!" << std::endl;
}

void    Harl::Info( void )
{
    std::cout << "I cannot believe adding extra bacon costs more money."<< std::endl << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void    Harl::Warning( void )
{
    std::cout << "I think I deserve to have some extra bacon for free."<< std::endl << "I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void    Harl::Error( void )
{
    std::cout << "This is unacceptable! I want to speak to the manager now."  << std::endl;
}

void    Harl::Complain( std:: string level )
{
    t_func ptrs[] = {&Harl::Debug, &Harl::Info, &Harl::Warning, &Harl::Error};
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    
    int i = 0;
    while (i < Limit)
    {
        if (level == levels[i])
            break ;
        i++;
    }

    switch (i)
    {
        case DEBUG:
            std::cout << "[ " << levels[0] << " ]\n";
            (this->*ptrs[DEBUG])();
        case INFO:
            std::cout << "[ " << levels[1] << " ]\n";
            (this->*ptrs[INFO])();
        case WARNING:
            std::cout << "[ " << levels[2] << " ]\n";
            (this->*ptrs[WARNING])();
        case ERROR:
            std::cout << "[ " << levels[3] << " ]\n";
            (this->*ptrs[ERROR])();
            break;
        default:
            std::cout <<"[ Probably complaining about insignificant problems ]\n";
    }
}
