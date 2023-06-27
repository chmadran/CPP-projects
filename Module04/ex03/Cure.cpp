/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 09:29:28 by chmadran          #+#    #+#             */
/*   Updated: 2023/06/27 09:59:05 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : _type("cure") {
	std::cout << "Cure default constructor constructor called." << std::endl;
}

Cure::Cure(const Cure& other) : _type(other.getType()) {
	std::cout << "Cure copy constructor constructor called." << std::endl;
}

Cure& Cure::operator=(const Cure& other) {
	return *this;
}

Cure::~Cure() {
	std::cout << "Cure destructor called." << std::endl;
}


Cure* Cure::clone() const { 
	return new Cure(*this); 
}

std::string const & Cure::getType() const {
	return (_type);
}


void Cure::use(ICharacter& target)
{
	std::string target_name = target.getName();
	std::cout << " heals " << target_name << "\'s wounds" << std::endl;
}