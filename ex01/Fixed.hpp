/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetit <lpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 08:54:08 by lpetit            #+#    #+#             */
/*   Updated: 2024/12/14 11:42:51 by lpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int 				_FixedPoint;
    static const int	_bits;
public:
    Fixed();
    ~Fixed();
	Fixed(const Fixed &copied);
	Fixed(const int value);
	Fixed(const float value);
	Fixed&	operator=(const Fixed& copied);
	int	getRawBits( void )const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& ostream, const Fixed& point);

#endif