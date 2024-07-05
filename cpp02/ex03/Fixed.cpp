/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 01:12:28 by muel-bak          #+#    #+#             */
/*   Updated: 2024/07/05 01:18:48 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    value = 0;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    if (this != &other)
    {
        this->setRawBits(other.getRawBits());
    }
    return (*this);
}

Fixed::Fixed(int const int_value)
{
    std::cout << "Int constructor called" << std::endl;
    value = int_value << fractional_bits;
}

Fixed::Fixed(float const float_value)
{
    std::cout << "Float constructor called" << std::endl;
    value = roundf(float_value * (1 << fractional_bits));
}

int Fixed::getRawBits() const
{
    return (value);
}

void Fixed::setRawBits(int const raw)
{
    value = raw;
}

float Fixed::toFloat() const
{
    return (static_cast<float>(value) / (1 << fractional_bits));
}

int Fixed::toInt() const
{
    return( value >> fractional_bits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
}

bool Fixed::operator>(const Fixed &other) const
{
    return (this->value > other.value);
}

bool Fixed::operator<(const Fixed &other) const
{
    return (this->value < other.value);
}

bool Fixed::operator>=(const Fixed &other) const
{
    return (this->value >= other.value);
}

bool Fixed::operator<=(const Fixed &other) const
{
    return (this->value <= other.value);
}

bool Fixed::operator==(const Fixed &other) const
{
    return (this->value == other.value);
}

bool Fixed::operator!=(const Fixed &other) const
{
    return (this->value != other.value);
}

Fixed Fixed::operator+(const Fixed &other) const
{
    return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed &other) const
{
    return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed &other) const
{
    return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed &other) const
{
    return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed &Fixed::operator++()
{
    ++value;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    ++value;
    return (temp);
}

Fixed &Fixed::operator--()
{
    --value;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    --value;
    return (temp);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return ((a < b) ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return ((a > b) ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return( (a > b) ? a : b);
}
