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

#include "iter.hpp"

void upperArrayChar(char &str) {
	if (str >= 'a' && str <= 'z')
		str -= 32;
}

int main( void ) {

	int intArray[] = {1, 2, 3, 4, 5};
	size_t intSize = sizeof(intArray) / sizeof(intArray[0]);

	HEADER("PRINT ELEMENT OF ARRAY 1")
	iter<int, void(*)(int)>(intArray, intSize, printArray);
	CR;

	double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	size_t doubleSize = sizeof(doubleArray) / sizeof(doubleArray[0]);

	HEADER("PRINT ELEMENT OF ARRAY 2")
	iter<double, void(*)(double)>(doubleArray, doubleSize, printArray);
	CR;

	HEADER("ARRAY OF CHAR BEFORE")
	char array[] = "bonjour";
	std::cout << array << std::endl;

	iter(array, 7, upperArrayChar);
	HEADER("ARRAY OF CHAR AFTER")
	std::cout << array << std::endl;
	CR;
}