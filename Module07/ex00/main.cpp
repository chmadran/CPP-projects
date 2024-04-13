/* ************************************************************************** */
/*                                                                           */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:01:12 by chmadran          #+#    #+#             */
/*   Updated: 2023/10/02 14:08:46 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define CR std::cout << std::endl;

#include "whatever.hpp"

int main( void ) {

	int a = 2;
	int b = 3;
	
	CR;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	
	CR;
	std::cout << "SWAPPING INTS" << std::endl;
	::swap( a, b );
	CR;
	
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	CR;
	
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	
	CR;
	std::string c = "chaine1";
	std::string d = "chaine2";
	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;

	CR;
	std::cout << "SWAPPING STRINGS" << std::endl;
	::swap( c, d );
	CR;
	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;
	CR;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	CR;
	double x = 3.14;
	double y = 2.71;
	std::cout << "x = " << x << std::endl;
	std::cout << "y = " << y << std::endl;

	CR;
	std::cout << "SWAPPING DOUBLES" << std::endl;
	::swap(x, y);
	CR;

	std::cout << "x = " << x << std::endl;
	std::cout << "y = " << y << std::endl;
	CR;

	std::cout << "min( x, y ) = " << ::min(x, y) << std::endl;
	std::cout << "max( x, y ) = " << ::max(x, y) << std::endl;

}