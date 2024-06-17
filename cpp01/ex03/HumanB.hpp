/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 20:52:21 by muel-bak          #+#    #+#             */
/*   Updated: 2024/06/17 20:46:53 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.hpp"

class HumanB
{
public:
    HumanB(std::string name);
    ~HumanB();
    void        attack() const;
    void        set_weapon(Weapon &_weapon);
    std::string name;
    private:
    Weapon	*weapon;
};

#endif