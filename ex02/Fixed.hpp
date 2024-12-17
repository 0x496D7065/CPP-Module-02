/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetit <lpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 08:54:08 by lpetit            #+#    #+#             */
/*   Updated: 2024/12/17 12:17:12 by lpetit           ###   ########.fr       */
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
	static Fixed&	min(Fixed& obj1, Fixed&obj2);
	static Fixed&	max(Fixed& obj1, Fixed&obj2);
	static const Fixed&	min(const Fixed& obj1, const Fixed&obj2);
	static const Fixed&	max(const Fixed& obj1, const Fixed&obj2);
	Fixed&	operator=(const Fixed& copied);
	Fixed&	operator++();
	Fixed&	operator--();
	Fixed	operator++(int);
	Fixed	operator--(int);
	Fixed	operator+(const Fixed& toAdd) const;
	Fixed	operator-(const Fixed& toAdd) const;
	Fixed	operator*(const Fixed& toAdd) const;
	Fixed	operator/(const Fixed& toAdd) const;
	int		operator>(const Fixed& toComp) const;
	int		operator<(const Fixed& toComp) const;
	int		operator>=(const Fixed& toComp) const;
	int		operator<=(const Fixed& toComp) const;
	int		operator==(const Fixed& toComp) const;
	int		operator!=(const Fixed& toComp) const;
	int	getRawBits( void )const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& ostream, const Fixed& point);
std::ostream& operator+(std::ostream& ostream, const Fixed& point);

#endif