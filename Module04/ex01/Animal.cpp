/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 09:46:06 by chmadran          #+#    #+#             */
/*   Updated: 2023/06/26 14:09:04 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal") {
	std::cout << "Animal default constructor called." << std::endl;
}

Animal::Animal(const Animal& rhs) {
	type = rhs.type;
	std::cout << "Animal copy constructor called." << std::endl;
}

Animal&	Animal::operator=(const	Animal& rhs) {
	type = rhs.type;
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal default destructor called." << std::endl;
}

std::string	Animal::getType() const {
	return type;
}

void	Animal::makeSound() const {
	std::cout << "The animal makes a generic sound." << std::endl;
}
