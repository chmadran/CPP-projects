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
#define HEADER(msg) std::cout << "---------" << msg << "---------" << std::endl;

#include "Array.hpp"

int main( void ) {

	HEADER("EMPTY ARRAYS");
	Array<int> empty_int_array(0);
	Array<std::string> empty_string_array(0);

	std::cout << "Empty int array size: " << empty_int_array.getSize() << std::endl;
	std::cout << "Empty string array size: " << empty_string_array.getSize() << std::endl;
	CR;
	
	Array<int> int_array(10);
	Array<std::string> string_array(10);

	for (int i = 0; i < 10; i++)
	{
		int_array[i] = i;
		string_array[i] = "Hello world";
	}

	HEADER("PRINTING ARRAY OF INT");
	for (int i = 0; i < 10; i++)
		std::cout << int_array[i];

	CR;
	CR;
	HEADER("PRINTING ARRAY OF CHAR");
	for (int i = 0; i < 10; i++)
		std::cout << string_array[i] << std::endl;

	CR;
	HEADER("PRINT SIZE OF ARRAYS");
	std::cout << "size : " << int_array.getSize() << std::endl;
	std::cout << "_size : " << string_array.getSize() << std::endl;

	CR;
	HEADER("COPYING & PRINTING ARRAY OF INTS");
	Array<int> int_array_copy(int_array);
	for (int i = 0; i < 10; i++)
	{
		std::cout << int_array_copy[i];
	}

	CR;
	HEADER("TESTING OUT OF INDEX IN ARRAY OF INTS");
	CR;
	try
	{
		int_array[12] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << "[error] " << e.what() << '\n';
	}

	HEADER("TESTING OUT OF INDEX IN ARRAY OF CHARS");
	CR;
	try
	{
		Array<std::string> integer(42);
		integer[39] = "Bob";
		std::cout << "_size of " << integer.getSize() << std::endl;
		std::cout << "value of " << integer[49] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	CR;
}