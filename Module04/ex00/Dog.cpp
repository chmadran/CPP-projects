/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 09:57:07 by chmadran          #+#    #+#             */
/*   Updated: 2023/06/26 14:05:19 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
	type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& rhs) : Animal (rhs) {
	type = rhs.getType();
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& rhs) {
	type = rhs.type;
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog default destructor called" << std::endl;
}

void	Dog::makeSound() const {
	std::cout << "[DOG SOUND] : Woof Woof" << std::endl;
}

std::string	Dog::getType() const {
	return type;
}