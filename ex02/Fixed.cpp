/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjelili <adjelili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 11:11:46 by adjelili          #+#    #+#             */
/*   Updated: 2026/05/07 13:05:15 by adjelili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	_fixedPoint = 0;
	std::cout << "Default constructor called\n";
}

Fixed::~Fixed(void)
{
	std::cout << "Default destructor called\n";
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called\n";
	*this = src;
}

Fixed::Fixed(int const value)
{
	std::cout << "Int constructor called\n";
	_fixedPoint = value << _fractionalBits;
}

Fixed::Fixed(float const value)
{
	std::cout << "Float constructor called\n";
	_fixedPoint = roundf(value * 256);
}

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

int	Fixed::toInt(void) const
{
	return (_fixedPoint >> 8);
}

float	Fixed::toFloat(void) const
{
	return ((float)_fixedPoint / _fractionalBits);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return (_fixedPoint);
}

Fixed	&Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &src)
		this->_fixedPoint = src.getRawBits();
	
	return (*this);
}

bool	Fixed::operator<(Fixed &rhs) const
{
	if (this->_fixedPoint < rhs.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator>(Fixed &rhs) const
{
	if (this->_fixedPoint > rhs.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator==(Fixed &rhs) const
{
	if (this->_fixedPoint == rhs.getRawBits())
		return (true);
	return (false);
}