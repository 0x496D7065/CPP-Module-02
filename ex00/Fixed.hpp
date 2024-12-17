/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetit <lpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 08:54:08 by lpetit            #+#    #+#             */
/*   Updated: 2024/12/14 10:25:08 by lpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
    int 				_FixedPoint;
    static const int	_bits;
public:
    Fixed();
    ~Fixed();
	Fixed(const Fixed &copied);
	Fixed&	operator=(const Fixed& copied);
	int	getRawBits( void )const;
	void setRawBits( int const raw );
};

#endif