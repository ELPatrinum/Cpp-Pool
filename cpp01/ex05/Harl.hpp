/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:52:49 by muel-bak          #+#    #+#             */
/*   Updated: 2024/06/19 12:30:59 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class   Harl
{
private:
    void    Debug( void );
    void    Info( void );
    void    Warning( void );
    void    Error( void );
public:
    Harl();
    ~Harl();
    void    Complain( std:: string level );
};

typedef void (Harl::*t_func) ( void );

#endif
