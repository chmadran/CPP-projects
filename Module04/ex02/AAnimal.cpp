/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 09:46:06 by chmadran          #+#    #+#             */
/*   Updated: 2023/09/26 18:03:00 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void) : _type("AAnimal") {
	std::cout << "AAnimal default constructor called." << std::endl;
}

AAnimal::AAnimal(std::string type): _type(type) {
	std::cout << "AAnimal string constructor called" << std::endl;
};

AAnimal::AAnimal(const AAnimal &original) {
	_type = original._type;
	std::cout << "AAnimal copy constructor called." << std::endl;
}

AAnimal::~AAnimal(void) {
	std::cout << "AAnimal default destructor called." << std::endl;
}

AAnimal&	AAnimal::operator=(const AAnimal& original) {
	if (this != &original)
		_type = original._type;
	return (*this);
}

std::string	AAnimal::getType(void) const {
	return (_type);
}

void	AAnimal::makeSound(void) const {
	std::cout << "The Aanimal makes a generic sound." << std::endl;
}
