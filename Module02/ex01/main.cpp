/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:49:47 by chmadran          #+#    #+#             */
/*   Updated: 2023/09/25 10:28:09 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	a = Fixed( 1234.4321f );
	
	std::cout << "___________________________________" << std::endl << std::endl;
	std::cout << "a is " << a << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "a is " << a.toFloat() << " as float" << std::endl;
	std::cout << "___________________________________" << std::endl << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toFloat() << " as float" << std::endl;
	std::cout << "___________________________________" << std::endl << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toFloat() << " as float" << std::endl;
	std::cout << "___________________________________" << std::endl << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toFloat() << " as float" << std::endl;
	std::cout << "___________________________________" << std::endl << std::endl;
	return 0;
}