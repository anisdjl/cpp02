/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anis <anis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 18:05:35 by adjelili          #+#    #+#             */
/*   Updated: 2026/05/07 23:14:05 by anis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0)
{
	std::cout << "Default constructor called\n";
}

Point::Point(float const x, float const y) : _x(x), _y(y)
{
	std::cout << "Constructor called\n";
}

Point::Point(const Point &src)
{
	*this = src;
	std::cout << "Copy constructor called\n";
}

Point &Point::operator=(Point const &src)
{
	(void)src;
	return *this;	
}

Point::~Point(void)
{
	std::cout << "Destructor called\n";
}

float	Point::get_x(void) const
{
	return (this->_x.getRawBits());
}

float	Point::get_y(void) const 
{
	return (this->_y.getRawBits());
}

