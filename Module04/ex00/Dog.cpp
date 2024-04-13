/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 09:57:07 by chmadran          #+#    #+#             */
/*   Updated: 2023/09/26 17:31:04 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog") {
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &original) : Animal(original._type) {
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog(void) {
	std::cout << "Dog default destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& original) {
	if (this != &original)
		_type = original._type;
	return (*this);
}

void	Dog::makeSound(void) const {
	std::cout << "[DOG SOUND] : Woof Woof" << std::endl;
}
