/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 09:57:07 by chmadran          #+#    #+#             */
/*   Updated: 2023/06/26 14:41:28 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat() {
	type = "Cat";
	brain = new Brain;
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& rhs) {
	type = rhs.getType();
	brain = new Brain(*(rhs.getBrain()));
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& rhs) {
	type = rhs.type;
	if (brain)
		delete (brain);
	brain = new Brain(*(rhs.getBrain()));
	return (*this);
}

Cat::~Cat() {
	delete brain;
	std::cout << "Cat default destructor called" << std::endl;
}

void	Cat::makeSound() const {
	std::cout << "[CAT SOUND] : Miaouw" << std::endl;
}

std::string	Cat::getType() const {
	return type;
}

Brain	*Cat::getBrain() const {
	return brain;
}