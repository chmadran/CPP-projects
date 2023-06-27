/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:50:51 by chmadran          #+#    #+#             */
/*   Updated: 2023/06/22 12:38:43 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( Fixed const & src) : _fixedValue(src._fixedValue) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return;
}

Fixed & Fixed::operator=(Fixed const & nbr) {
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &nbr){
		this->_fixedValue = nbr.getRawBits();
	} 
	return *this;
}

int	Fixed::getRawBits( void ) const {
	std::cout << "getRawBits function called" << std::endl;
	return this->_fixedValue;
}

void Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits function called" << std::endl;
	this->_fixedValue = raw;
	return;
}