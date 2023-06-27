/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:50:51 by chmadran          #+#    #+#             */
/*   Updated: 2023/06/22 14:08:24 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

const int Fixed::_nBits = 8;

Fixed::Fixed() : _fixedValue(0) {
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
	//std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int nbr) : _fixedValue(nbr << _nBits) {
	//std::cout << "Int constructor called" << std::endl;
	return;
}

Fixed::Fixed(const float nbr) : _fixedValue(std::roundf( nbr * ( 1 << _nBits ) ) ) {
	//std::cout << "Float constructor called" << std::endl;
	return;
}

Fixed::Fixed( Fixed const & src) {
	//std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return;
}

Fixed & Fixed::operator=(Fixed const & nbr) {
	//std::cout << "Copy assignement operator called" << std::endl;
	if (this != &nbr){
		this->_fixedValue = nbr.getRawBits();
	} 
	return *this;
}

int	Fixed::getRawBits( void ) const {
	return this->_fixedValue;
}

void Fixed::setRawBits( int const raw ) {
	//std::cout << "setRawBits function called" << std::endl;
	this->_fixedValue = raw;
	return;
}

float Fixed::toFloat() const {
    return static_cast<float>( this->getRawBits() ) / ( 1 << _nBits );
}

int Fixed::toInt() const {
    return this->_fixedValue / (1 << _nBits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}


bool Fixed::operator>(const Fixed& other) const {
    return this->_fixedValue > other._fixedValue;
}

bool Fixed::operator<(const Fixed& other) const {
    return this->_fixedValue < other._fixedValue;
}


bool Fixed::operator>=(const Fixed& other) const {
    return this->_fixedValue >= other._fixedValue;
}

bool Fixed::operator<=(const Fixed& other) const {
    return this->_fixedValue <= other._fixedValue;
}

Fixed	Fixed::operator+(const Fixed& other) const {
	int resultValue = this->_fixedValue + other._fixedValue;
	Fixed result(resultValue);
	return result;
}

Fixed	Fixed::operator-(const Fixed& other) const {
	int resultValue = this->_fixedValue - other._fixedValue;
	Fixed result(resultValue);
	return result;
}

Fixed	Fixed::operator*(const Fixed& other) const {
	int resultValue = this->_fixedValue * other._fixedValue;
	Fixed result(resultValue);
	return result;
}

Fixed	Fixed::operator/(const Fixed& other) const {
	int resultValue = this->_fixedValue / other._fixedValue;
	Fixed result(resultValue);
	return result;
}

Fixed& Fixed::operator++()
{
	_fixedValue += 1;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	++(*this);
	return temp;
}

Fixed& Fixed::operator--()
{
	_fixedValue -= 1;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	--(*this);
	return temp;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    return (a < b) ? a : b;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return (a < b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return (a > b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return (a > b) ? a : b;
}