/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetit <lpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 08:55:11 by lpetit            #+#    #+#             */
/*   Updated: 2024/12/16 13:56:29 by lpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main( void )
{
	Fixed	a;
	Fixed	b( 10 );
	Fixed	c( 42.42f);																//This example is for why rounding is necessary in the conversion process
	Fixed	d( b );																	//42.42 is stored as a close aproximation as 42.421999999999999
																					//When scaling 42.42 by a factor of 256(8bits) it becomes 10899.52 which would be truncated to 10899
	a = Fixed( 1234.4321f );														//and result to 42.418 when converted back.
																					//Rounding up makes it to 10900 which gives a more precise conversion.
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
}