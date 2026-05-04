/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjelili <adjelili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 13:21:51 by adjelili          #+#    #+#             */
/*   Updated: 2026/05/04 18:04:01 by adjelili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

Fixed::Fixed(void)
{
	this->_fixedPoint = 0;
	std::cout << "Default Constructor called\n";
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called\n";
}

float	Fixed::toFloat(void) const
{
	return ((float)_fixedPoint / 256);
}

Fixed::Fixed(const Fixed &src) // pareil qu'un constructeur par default sauf qu'il recoit unn objet par refernce
{
	std::cout << "Copy constructor called\n";
	*this = src;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return (_fixedPoint);	
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixedPoint = raw;
}

Fixed	&Fixed::operator=(const Fixed &src) // il faut tout le temps checker si c'est pas le meme pour eviter l'auto assignation
{
	std::cout << "Copy assignment operator called\n";

	if (this != &src)
		this->_fixedPoint = src.getRawBits();

	return (*this);
}

int		Fixed::toInt(void) const
{
	return (_fixedPoint >> 8);
}

Fixed::Fixed(int const value)
{
	_fixedPoint = value << Fixed::_fractionalBits;
	std::cout << "Int constructor called\n";
}

Fixed::Fixed(float const value)
{
	std::cout << "Float constructor called\n";
	_fixedPoint = roundf(value * 256);
}
