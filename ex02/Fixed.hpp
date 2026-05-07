/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjelili <adjelili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 10:41:45 by adjelili          #+#    #+#             */
/*   Updated: 2026/05/07 12:38:39 by adjelili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int 				_fixedPoint;
		static const int	_fractionalBits;
	public:
		Fixed(void);
		~Fixed(void);
		Fixed(const Fixed &src);
		Fixed(int const value);
		Fixed(float const value);
		Fixed	&operator=(const Fixed &src);

		void	setRawBits(int const raw);
		int		getRawBits(void) const;
		float	toFloat(void) const;
		int		toInt(void) const;
		
		static const Fixed	&min(Fixed &fixed1, Fixed &fixed2);
		static const Fixed	&min(Fixed const &fixed1, Fixed const &fixed2);
		static const Fixed	&max(Fixed &fixed1, Fixed &fixed2);
		static const Fixed	&max(Fixed const &fixed1, Fixed const &fixed2);
		
		bool	operator<(Fixed &rhs) const;
		bool	operator>(Fixed &rhs) const;
		bool	operator==(Fixed &rhs) const;
		bool	operator!=(Fixed &rhs) const;
		bool	operator<=(Fixed &rhs) const;
		bool	operator>=(Fixed &rhs) const;
		
		Fixed	operator+(Fixed const &rhs) const;
		Fixed	operator-(Fixed const &rhs) const;
		Fixed	operator*(Fixed const &rhs) const;
		Fixed	operator/(Fixed const &rhs) const;
};

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed);
#endif