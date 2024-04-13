/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:14:49 by chmadran          #+#    #+#             */
/*   Updated: 2023/09/20 16:42:57 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
	std::string 	string = "HI THIS IS BRAIN";
	std::string*	stringPTR = &string;
	std::string&	stringREF = string;
	
	std::cout << "PRINTING MEMORY ADDRESSES" << std::endl;
	std::cout << &string << std::endl;
	std::cout << &stringPTR << std::endl;
	std::cout << &stringREF << std::endl << std::endl;

	std::cout << "PRINTING VARIABLE VALUES" << std::endl;
	std::cout << string << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;
}
