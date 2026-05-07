/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjelili <adjelili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 17:59:23 by adjelili          #+#    #+#             */
/*   Updated: 2026/05/07 18:32:19 by adjelili         ###   ########.fr       */
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
		float	globalArea(Fixed const a, Fixed const b, Fixed const c);
		float	localArea(Fixed const a, Fixed const b, Fixed const point);
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif