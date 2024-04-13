/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:50:51 by chmadran          #+#    #+#             */
/*   Updated: 2023/09/25 11:58:15 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _fixedValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int nbr) : _fixedValue(nbr << _nBits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float nbr) : _fixedValue(std::roundf(nbr * ( 1 << _nBits))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed &Fixed::operator=(Fixed const &nbr) {
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &nbr){
		_fixedValue = nbr.getRawBits();
	} 
	return (*this);
}

int	Fixed::getRawBits( void ) const {
	return (_fixedValue);
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits function called" << std::endl;
	_fixedValue = raw;
}

float Fixed::toFloat() const {
	return ((static_cast<float>(this->getRawBits())) / (1 << _nBits));
}

int Fixed::toInt() const {
	return (_fixedValue >> _nBits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return (os);
}