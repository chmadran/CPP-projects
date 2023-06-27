/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 09:46:06 by chmadran          #+#    #+#             */
/*   Updated: 2023/06/26 14:55:11 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal") {
	std::cout << "AAnimal default constructor called." << std::endl;
}

AAnimal::AAnimal(const AAnimal& rhs) {
	type = rhs.type;
	std::cout << "AAnimal copy constructor called." << std::endl;
}

AAnimal&	AAnimal::operator=(const	AAnimal& rhs) {
	type = rhs.type;
	return *this;
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal default destructor called." << std::endl;
}

std::string	AAnimal::getType() const {
	return type;
}

void	AAnimal::makeSound() const {
	std::cout << "The Aanimal makes a generic sound." << std::endl;
}
