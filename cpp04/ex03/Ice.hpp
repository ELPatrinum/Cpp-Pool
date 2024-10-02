/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:04:29 by muel-bak          #+#    #+#             */
/*   Updated: 2024/10/02 16:31:50 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice : public AMateria
{
public :
	Ice();
	Ice(const Ice &other);
	virtual ~Ice();
	Ice &operator=(const Ice &other);
	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif