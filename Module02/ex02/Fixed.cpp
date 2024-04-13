/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:50:51 by chmadran          #+#    #+#             */
/*   Updated: 2023/09/25 12:08:24 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void) : _fixedValue(0) {
}

Fixed::~Fixed(void) {
}

Fixed::Fixed(const int nbr) : _fixedValue(nbr << _nBits) {
}

Fixed::Fixed(const float nbr) : _fixedValue(std::roundf(nbr * ( 1 << _nBits ))) {
}

Fixed::Fixed(Fixed const &fixed) {
	*this = fixed;
}

Fixed &Fixed::operator=(const Fixed &nbr) {
	if (this != &nbr){
		_fixedValue = nbr.getRawBits();
	}
	return (*this);
}

int	Fixed::getRawBits( void ) const {
	return (_fixedValue);
}

void Fixed::setRawBits( int const raw ) {
	_fixedValue = raw;
}

float Fixed::toFloat() const {
	return ((static_cast<float>(this->getRawBits())) / ( 1 << _nBits ));
}

int Fixed::toInt() const {
	return (_fixedValue / (1 << _nBits));
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return (os);
}

bool	Fixed::operator>(const Fixed &fixed) const {
	return(this->toFloat() > fixed.toFloat());
};

bool	Fixed::operator>=(const Fixed &fixed) const {
	return(this->toFloat() >= fixed.toFloat());
};

bool	Fixed::operator<(const Fixed &fixed) const {
	return(this->toFloat() < fixed.toFloat());
};

bool	Fixed::operator<=(const Fixed &fixed) const {
	return(this->toFloat() <= fixed.toFloat());
};

bool	Fixed::operator==(const Fixed &fixed) const {
	return(this->toFloat() == fixed.toFloat());
};

bool	Fixed::operator!=(const Fixed &fixed) const {
	return(this->toFloat() != fixed.toFloat());
};

Fixed	Fixed::operator+(const Fixed &fixed) const {
	return (Fixed(this->toFloat() + fixed.toFloat()));
};

Fixed	Fixed::operator-(const Fixed &fixed) const {
	return (Fixed(this->toFloat() - fixed.toFloat()));
};

Fixed	Fixed::operator*(const Fixed &fixed) const {
	return (Fixed(this->toFloat() * fixed.toFloat()));
};

Fixed	Fixed::operator/(const Fixed &fixed) const {
	if (fixed.getRawBits() == 0)
	{
		std::cerr << "Divinding by 0 is not possbile" << std::endl;
		return (this->toFloat());
	}
	return ( (this->toFloat() / fixed.toFloat()));
};

Fixed& Fixed::operator++(void)
{
	_fixedValue++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	++(_fixedValue);
	return (temp);
}

Fixed& Fixed::operator--(void)
{
	_fixedValue--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	--(_fixedValue);
	return (temp);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return ((a < b) ? a : b);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return ((a < b) ? a : b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return ((a > b) ? a : b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return ((a > b) ? a : b);
}