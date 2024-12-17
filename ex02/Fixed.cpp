/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetit <lpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 08:55:07 by lpetit            #+#    #+#             */
/*   Updated: 2024/12/17 12:17:28 by lpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_bits = 8;

Fixed::Fixed()
{
	_FixedPoint = 0;
	//std :: cout << "Default constructor called\n";
}

Fixed::~Fixed()
{
	//std :: cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed &copied)
{
	//std :: cout << "Copy constructor called\n";
	*this = copied;
}

Fixed::Fixed(const int value)
{
	this->_FixedPoint = value * (1 << this->_bits);										  //scale integer by 2^bits
	//std :: cout << "Int constructor called\n";
}

Fixed::Fixed(const float value)
{
	this->_FixedPoint = static_cast<int>(roundf(value * (1 << this->_bits)));					  //scale float by 2^bits
	//std :: cout << "Float constructor called\n";
}

Fixed& Fixed::operator=(const Fixed& copied)
{
	if (this != &copied)
	{
		//std :: cout << "Copy assignment operator called\n";
		_FixedPoint = copied.getRawBits();
	}
	return (*this);
}

int Fixed::getRawBits( void ) const
{
	//std :: cout << "getRawBits member function called\n";
	return (this->_FixedPoint);
}

void Fixed::setRawBits( int const raw )
{
	this->_FixedPoint = raw;
	//std :: cout << "setRawBits member function called\n";
}

float Fixed::toFloat( void ) const								   //Divide fixedpoint by 2^bits
{
	return (static_cast<float>(roundf(this->_FixedPoint) / (1 << this->_bits)));
}

int Fixed::toInt( void ) const									   //Conversion process is the same for both int and float
{																   //Only the return format changes. Int truncates float anyway
	return (this->_FixedPoint / (1 << this->_bits));
}

std::ostream& operator<<(std::ostream &os, const Fixed &point)     //Necessary for cout to convert the object to an 
{																   //appropriate format to print
	os << point.toFloat();
	return (os);
}

Fixed Fixed::operator+(const Fixed& toAdd) const
{
	Fixed	result;

	result.setRawBits(this->_FixedPoint + toAdd._FixedPoint);
	return (result);
}

Fixed Fixed::operator-(const Fixed& toAdd) const
{
	Fixed	result;

	result.setRawBits(this->_FixedPoint - toAdd._FixedPoint);
	return (result);
}

Fixed Fixed::operator*(const Fixed& toAdd) const
{
	Fixed	result;

	long long temp = static_cast<long long>(this->_FixedPoint) * static_cast<long long>(toAdd._FixedPoint);	//Multiply raw value in a temp variable to avoid int overflow before scaling back
	result.setRawBits(static_cast<int>(temp >> this->_bits));												//Divide the result by 2^bits because scaling factor got squarred
	return (result);
}

Fixed Fixed::operator/(const Fixed& toAdd) const
{
	Fixed	result;

	long long temp = (static_cast<long long>(this->_FixedPoint) << this->_bits) / static_cast<long long>(toAdd._FixedPoint);
	result.setRawBits(static_cast<int>(temp));
	return (result);
}

int Fixed::operator>(const Fixed& toAdd) const
{
	if (this->_FixedPoint > toAdd._FixedPoint)
		return (1);
	else
		return (0);
}

int Fixed::operator<(const Fixed& toAdd) const
{
	if (this->_FixedPoint < toAdd._FixedPoint)
		return (1);
	else
		return (0);
}

int Fixed::operator>=(const Fixed& toAdd) const
{
	if (this->_FixedPoint >= toAdd._FixedPoint)
		return (1);
	else
		return (0);
}

int Fixed::operator<=(const Fixed& toAdd) const
{
	if (this->_FixedPoint <= toAdd._FixedPoint)
		return (1);
	else
		return (0);
}

int Fixed::operator==(const Fixed& toAdd) const
{
	if (this->_FixedPoint == toAdd._FixedPoint)
		return (1);
	else
		return (0);
}

int Fixed::operator!=(const Fixed& toAdd) const
{
	if (this->_FixedPoint != toAdd._FixedPoint)
		return (1);
	else
		return (0);
}

Fixed&	Fixed::operator++()
{
	this->_FixedPoint += 1;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp(*this);

	this->_FixedPoint += 1;
	return (temp);
}

Fixed&	Fixed::operator--()
{
	this->_FixedPoint -= 1;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);

	this->_FixedPoint -= 1;
	return (temp);
}

Fixed&	Fixed::min(Fixed& obj1, Fixed&obj2)
{
	if (obj1 < obj2)
		return (obj1);
	return (obj2);
}

Fixed&	Fixed::max(Fixed& obj1, Fixed&obj2)
{
	if (obj1 > obj2)
		return (obj1);
	return (obj2);
}

const Fixed&	Fixed::min(const Fixed& obj1, const Fixed&obj2)
{
	if (obj1 < obj2)
		return (obj1);
	return (obj2);
}

const Fixed&	Fixed::max(const Fixed& obj1, const Fixed&obj2)
{
	if (obj1 > obj2)
		return (obj1);
	return (obj2);
}