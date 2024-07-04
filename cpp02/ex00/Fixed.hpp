/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 22:05:02 by muel-bak          #+#    #+#             */
/*   Updated: 2024/07/04 23:11:53 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

# include <iostream>

class Fixed
{
private:
	int 				value;
	static const int	fractional_bits = 8;
public:
	Fixed();
	~Fixed();
	Fixed &operator=(const Fixed &other);
	Fixed(const Fixed &other);
	int getRawBits() const;
	void setRawBits(int const raw);
};
#endif