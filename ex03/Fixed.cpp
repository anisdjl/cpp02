/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anis <anis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 17:51:11 by adjelili          #+#    #+#             */
/*   Updated: 2026/05/08 00:15:27 by anis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

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
	return ((float)_fixedPoint / 256);
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

bool	Fixed::operator!=(Fixed &rhs) const
{
	if (this->_fixedPoint != rhs.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator>=(Fixed &rhs) const
{
	if (this->_fixedPoint >= rhs.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<=(Fixed &rhs) const
{
	if (this->_fixedPoint <= rhs.getRawBits())
		return (true);
	return (false);
}

Fixed	Fixed::operator+(Fixed const &rhs) const
{
	Fixed	addition;
	
	addition.setRawBits(_fixedPoint + rhs.getRawBits());
	return (addition);
}

Fixed	Fixed::operator-(Fixed const &rhs) const
{
	Fixed	soustraction;

	soustraction.setRawBits(_fixedPoint - rhs.getRawBits());
	return (soustraction);
}

Fixed	Fixed::operator*(Fixed const &rhs) const
{
	Fixed 	multi;
	
	multi.setRawBits(((long)_fixedPoint * rhs.getRawBits()) / 256);
	return (multi);
}

Fixed	Fixed::operator/(Fixed const &rhs) const
{
	return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed	&Fixed::operator++(void)
{
	_fixedPoint++;
	
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp = *this;

	++_fixedPoint;
	return (temp);
}

Fixed	&Fixed::operator--(void)
{
	_fixedPoint--;
	
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp = *this;

	--_fixedPoint;
	return (temp);
}

const Fixed	&Fixed::min(Fixed &fixed1, Fixed &fixed2)
{
	if (fixed1.getRawBits() < fixed2.getRawBits())
		return (fixed1);
	return (fixed2);
}

const Fixed	&Fixed::min(Fixed const &fixed1, Fixed const &fixed2)
{
	if (fixed1.getRawBits() < fixed2.getRawBits())
		return (fixed1);
	return (fixed2);
}

const Fixed	&Fixed::max(Fixed &fixed1, Fixed &fixed2)
{
	if (fixed1.getRawBits() > fixed2.getRawBits())
		return (fixed1);
	return (fixed2);
}

const Fixed	&Fixed::max(Fixed const &fixed1, Fixed const &fixed2)
{
	if (fixed1.getRawBits() > fixed2.getRawBits())
		return (fixed1);
	return (fixed2);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixedPoint = raw;
}
