/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 09:29:30 by chmadran          #+#    #+#             */
/*   Updated: 2023/06/27 10:43:41 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : _type("ice") {
	std::cout << "Ice default constructor constructor called." << std::endl;
}

Ice::Ice(const Ice& other) : _type(other.getType()) {
	std::cout << "Ice copy constructor constructor called." << std::endl;
}

Ice& Ice::operator=(const Ice& other) {
	return *this;
}

Ice::~Ice() {
	std::cout << "Ice destructor called." << std::endl;
}


Ice* Ice::clone() const { 
	return new Ice(*this); 
}

std::string const & Ice::getType() const {
	return (_type);
}


void Ice::use(ICharacter& target)
{
	std::string target_name = target.getName();
	std::cout << " shoots an ice bolts at " << target_name << std::endl;
}