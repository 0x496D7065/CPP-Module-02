/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetit <lpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 08:55:11 by lpetit            #+#    #+#             */
/*   Updated: 2024/12/14 09:46:00 by lpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main( void )
{
	Fixed	a;
	Fixed	b( a );
	Fixed	c;

	c = b;

	std :: cout << a.getRawBits() << std :: endl;
	std :: cout << b.getRawBits() << std :: endl;
	std :: cout << c.getRawBits() << std :: endl;
}