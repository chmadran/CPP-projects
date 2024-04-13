/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:50:51 by chmadran          #+#    #+#             */
/*   Updated: 2023/09/25 12:36:33 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _fixedValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed &Fixed::operator=(const Fixed &nbr) {
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &nbr){
		_fixedValue = nbr.getRawBits();
	} 
	return (*this);
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits function called" << std::endl;
	return (_fixedValue);
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits function called" << std::endl;
	_fixedValue = raw;
}