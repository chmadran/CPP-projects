/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 09:57:07 by chmadran          #+#    #+#             */
/*   Updated: 2023/06/26 14:05:10 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
	type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& rhs) {
	type = rhs.getType();
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& rhs) {
	type = rhs.type;
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat default destructor called" << std::endl;
}

void	Cat::makeSound() const {
	std::cout << "[CAT SOUND] : Miaouw" << std::endl;
}

std::string	Cat::getType() const {
	return type;
}