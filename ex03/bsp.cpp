/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anis <anis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 17:51:17 by adjelili          #+#    #+#             */
/*   Updated: 2026/05/07 23:13:09 by anis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

float globalArea(Point const a, Point const b, Point const c)
{
	float	globalarea;

	globalarea = 1/2 * (a.get_x() * (b.get_y() - c.get_y()) + b.get_x() * (a.get_y() - c.get_y()) + c.get_x() * (a.get_x() + b.get_y()));
	if (globalarea < 0)
		return (globalarea * (-1));
	return (globalarea);
}

float	localArea(Point const a, Point const b, Point const point)
{
	float	larea;

	larea = 1/2 * (a.get_x() * (b.get_y() - point.get_y()) + b.get_x() * (a.get_y() - point.get_y()) + point.get_x() * (a.get_x() + b.get_y()));
	if (larea < 0)
		return (larea * (-1));
	return (larea);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	float	area_one;
	float	area_two;
	float	area_three;
	float	global_area;

	global_area = localArea(a, b, c);
	area_one = localArea(a, b, point);
	area_two = localArea(a, c, point);
	area_three = localArea(b, c , point);

	if (area_one + area_two + area_three == global_area)
		return (true);
	return (false);
}
