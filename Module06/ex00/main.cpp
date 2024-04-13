/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:47:25 by chmadran          #+#    #+#             */
/*   Updated: 2023/10/02 11:48:18 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define CR std::cout << std::endl;

#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
	if(argc != 2)
	{
		std::cout << "Wrong number of arguments" << std::endl;
		return 1;
	}
	ScalarConverter::convert(argv[1]);
}