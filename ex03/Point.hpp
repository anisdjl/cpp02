/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anis <anis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 17:59:23 by adjelili          #+#    #+#             */
/*   Updated: 2026/05/08 00:04:36 by anis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		const Fixed _x;
		const Fixed _y;
	public:
		Point(void);
		Point(float const x, float const y);
		Point(Point const &src);
		Point &operator=(Point const &src);
		~Point(void);
		float	get_x(void) const;
		float	get_y(void) const;
};

float	globalArea(Point const &a, Point const &b, Point const &c);
float	localArea(Point const &a, Point const &b, Point const &point);
bool	bsp(Point const &a, Point const &b, Point const &c, Point const &point);

#endif