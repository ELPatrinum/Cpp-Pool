/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:23:24 by muel-bak          #+#    #+#             */
/*   Updated: 2024/10/02 16:31:44 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure : public AMateria
{
public :
	Cure();
	Cure(const Cure &other);
	virtual ~Cure();
	Cure &operator=(const Cure &other);
	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif