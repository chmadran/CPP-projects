/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:24:16 by chmadran          #+#    #+#             */
/*   Updated: 2023/06/21 16:33:34 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv){
	
	Harl 			test;

	std::string		arg;
	while (arg != "EXIT")
	{
		std::cout << "Please enter a level to see Harl complain.. (DEBUG, INFO, WARNING, ERROR), else EXIT : " << std::endl;
		std::cin >> arg;
		test.complain(arg);
	}
}