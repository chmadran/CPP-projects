/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:00:48 by chmadran          #+#    #+#             */
/*   Updated: 2023/09/26 17:22:31 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("WrongAnimal") {
	std::cout << "WrongAnimal default constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) {
	std::cout << "WrongAnimal string constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &original) {
	_type = original._type;
	std::cout << "WrongAnimal copy constructor called." << std::endl;
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << "WrongAnimal default destructor called." << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const	WrongAnimal& original) {
	if (this != &original)
		_type = original._type;
	return (*this);
}

std::string	WrongAnimal::getType(void) const {
	return (_type);
}

void	WrongAnimal::makeSound(void) const {
	std::cout << "The Wrong Animal makes a generic sound." << std::endl;
}