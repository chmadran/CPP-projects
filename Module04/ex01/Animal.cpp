/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 09:46:06 by chmadran          #+#    #+#             */
/*   Updated: 2023/09/26 17:13:55 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : _type("Animal") {
	std::cout << "Animal default constructor called." << std::endl;
}

Animal::Animal(std::string type) : _type(type) {
	std::cout << "Animal string constructor called." << std::endl;
}

Animal::Animal(const Animal &original) {
	_type = original._type;
	std::cout << "Animal copy constructor called." << std::endl;
}

Animal::~Animal(void) {
	std::cout << "Animal default destructor called." << std::endl;
}

Animal &Animal::operator=(const	Animal &original) {
	if (this != &original)
		_type = original._type;
	return (*this);
}

std::string	Animal::getType(void) const {
	return (_type);
}

void	Animal::makeSound(void) const {
	std::cout << "The animal makes a generic sound." << std::endl;
}
