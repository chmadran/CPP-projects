/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 09:57:07 by chmadran          #+#    #+#             */
/*   Updated: 2023/06/26 14:43:06 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog() {
	type = "Dog";
	brain = new Brain;
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& rhs) {
	type = rhs.getType();
	brain = new Brain(*(rhs.getBrain()));
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& rhs) {
	type = rhs.type;
	if (brain)
		delete (brain);
	brain = new Brain(*(rhs.getBrain()));
	return (*this);
}

Dog::~Dog() {
	delete brain;
	std::cout << "Dog default destructor called" << std::endl;
}

void	Dog::makeSound() const {
	std::cout << "[DOG SOUND] : WOOF" << std::endl;
}

std::string	Dog::getType() const {
	return type;
}

Brain	*Dog::getBrain() const {
	return brain;
}