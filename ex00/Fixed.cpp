/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetit <lpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 08:55:07 by lpetit            #+#    #+#             */
/*   Updated: 2024/12/14 11:29:39 by lpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_bits = 8;

Fixed::Fixed()
{
	_FixedPoint = 0;
	std :: cout << "Default constructor called\n";
}

Fixed::~Fixed()
{
	std :: cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed &copied)
{
	std :: cout << "Copy constructor called\n";
	*this = copied;
}

Fixed& Fixed::operator=(const Fixed& copied)
{
	if (this != &copied)
	{
		std :: cout << "Copy assignment operator called\n";
		_FixedPoint = copied.getRawBits();
	}
	return (*this);
}

int Fixed::getRawBits( void ) const
{
	std :: cout << "getRawBits member function called\n";
	return (this->_FixedPoint);
}

void Fixed::setRawBits( int const raw )
{
	this->_FixedPoint = raw;
	std :: cout << "setRawBits member function called\n";
}