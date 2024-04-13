/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 09:57:07 by chmadran          #+#    #+#             */
/*   Updated: 2023/09/26 17:26:54 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat") {
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &original) : Animal(original._type) {
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat(void) {
	std::cout << "Cat default destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat &original) {
	if (this != &original) 
		_type = original._type;
	return (*this);
}

void	Cat::makeSound(void) const {
	std::cout << "[CAT SOUND] : Miaouw" << std::endl;
}
