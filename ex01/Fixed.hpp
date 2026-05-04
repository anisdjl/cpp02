/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjelili <adjelili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 13:21:45 by adjelili          #+#    #+#             */
/*   Updated: 2026/05/04 17:47:15 by adjelili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
	private:
		int					_fixedPoint;
		static const int	_fractionalBits;
	public:
		Fixed(void);
		~Fixed(void);
		Fixed(const Fixed &src);
		int	getRawBits(void) const;
		void setRawBits(int const raw);
		Fixed	&operator=(const Fixed &src);
		Fixed(int const value);
		Fixed(float const value);
		float	toFloat(void) const;
		int		toInt(void) const;
	};
	
	std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
#endif
