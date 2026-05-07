/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anis <anis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 17:51:44 by adjelili          #+#    #+#             */
/*   Updated: 2026/05/07 23:41:24 by anis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

const int	Fixed::_fractionalBits = 8;
int main(void)
{
	Point A = Point(0, 0);
	Point B = Point(10, 0);
	Point C = Point(5, 10);
	Point point = Point(5, 11);

	std::cout << bsp(A, B, C, point) << std::endl;

	return (0);
}