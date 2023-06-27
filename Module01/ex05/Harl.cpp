/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:25:48 by chmadran          #+#    #+#             */
/*   Updated: 2023/06/21 16:35:27 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::complain( std::string level ) {
	FunctionPtr funcptr = nullptr;
	
	if (level == "DEBUG") {
		funcptr = &Harl::debug;
	}
	else if (level == "INFO") {
		funcptr = &Harl::info;
	}
	else if (level == "WARNING") {
		funcptr = &Harl::warning;
	}
	else if (level == "ERROR") {
		funcptr = &Harl::error;
	}
	else if (level == "EXIT") {
		return; }
	else {
		std::cout << "Invalid Level : " << level << std::endl << std::endl;
		return ;
	}
	(this->*funcptr)();
}

Harl::Harl(){
	return;
}

Harl::~Harl(){
	return;
}

void Harl::debug( void ) {
	std::cout << std::endl << "[This is a debug message.]" << std::endl << std::endl;
}

void Harl::info( void ){
	std::cout << std::endl << "[This is an info message.]" << std::endl << std::endl;
}

void Harl::warning( void ){
	std::cout << std::endl << "[This is a warning message.]" << std::endl << std::endl;
}

void Harl::error( void ){
	std::cout << std::endl << "[This is an error message.]" << std::endl << std::endl;
}