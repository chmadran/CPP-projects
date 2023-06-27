/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:25:48 by chmadran          #+#    #+#             */
/*   Updated: 2023/06/21 16:26:59 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::complain( std::string level ) {
	int levelValue = 0;
	
	if (level == "DEBUG") {
		levelValue = 1;
	}
	else if (level == "INFO") {
		levelValue = 2;
	}
	else if (level == "WARNING") {
		levelValue = 3;
	}
	else if (level == "ERROR") {
		levelValue = 4;
	}
	else if (level == "EXIT") {
		return;
	}
	else {
		std::cout << "Invalid Level : " << level << std::endl;
		return ;
	}
	switch(levelValue) {
		case 1:
			debug();
		case 2:
			info();
		case 3:
			warning();
		case 4:
			error();
	}
}

Harl::Harl(){
	return;
}

Harl::~Harl(){
	return;
}

void Harl::debug( void ) {
	std::cout << "This is a debug message." << std::endl;
}

void Harl::info( void ){
	std::cout << "This is an info message." << std::endl;
}

void Harl::warning( void ){
	std::cout << "This is a warning message." << std::endl;
}

void Harl::error( void ){
	std::cout << "This is an error message." << std::endl;
}