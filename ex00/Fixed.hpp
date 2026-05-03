/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anis <anis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 19:37:48 by anis              #+#    #+#             */
/*   Updated: 2026/05/03 22:27:18 by anis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
	private:
		int	_fixedPoint;
		static const int	fractionalBits;
	public:
		Fixed(void);
		~Fixed(void);
		Fixed(const Fixed &src);
		int	getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif