/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 13:59:57 by chmadran          #+#    #+#             */
/*   Updated: 2023/09/26 17:26:28 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat") {
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& original) : WrongAnimal(original._type) {
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat::~WrongCat(void) {
	std::cout << "WrongCat default destructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& original) {
	if (this != &original)
		_type = original._type;
	return (*this);
}

void	WrongCat::makeSound(void) const {
	std::cout << "[WRONGCAT SOUND] : Miaouw" << std::endl;
}