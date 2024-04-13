/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:15:57 by chmadran          #+#    #+#             */
/*   Updated: 2023/10/04 10:14:11 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/************************************************************
 *					CONSTRUCTORS/DESTRUCTOR					*
 ************************************************************/

Span::Span() {};

Span::Span(unsigned int N) : _lenContainer(N) {
	if (_lenContainer > _intContainer.max_size())
		throw Span::ContainerTooSmall();
};

Span::Span(const Span &src) { (void)src; };

Span::~Span() {};

Span	&Span::operator=(const Span &src){
	if (this != &src)
	{
		_lenContainer = src._lenContainer;
		_intContainer = src._intContainer;
	}
	return (*this);
};

/************************************************************
 *						METHODS								*
 ************************************************************/

void	Span::addNumber(int nb) {
	if (_intContainer.size() == _lenContainer)
		throw Span::ContainerFull();
	_intContainer.push_back(nb);
};

void	Span::addNumber(std::vector<int> tabInt) {
	if (_intContainer.size() + tabInt.size() > _lenContainer)
		throw Span::ContainerFull();
	_intContainer.insert(_intContainer.end(), tabInt.begin(), tabInt.end());
};

int	Span::shortestSpan() {
	int	len = _intContainer.size();
	if (len <= 1)
		throw Span::NoSpan();
	std::sort(_intContainer.begin(), _intContainer.end()); // sort in ascending order
	int	dif = abs(_intContainer[1] - _intContainer[0]);
	for (int i = 1; i < len - 1; ++i)
	{
		if (abs(_intContainer[i + 1] - _intContainer[i]) < dif)
			dif = abs(_intContainer[i + 1] - _intContainer[i]);
	}
	return (dif);
};

int	Span::longestSpan() {
	int	len = _intContainer.size();
	if (len <= 1)
		throw Span::NoSpan();
	std::sort(_intContainer.begin(), _intContainer.end()); // sort in ascending order
	return(abs(_intContainer[len - 1] - _intContainer[0]));
};

/************************************************************
 *						EXCEPTIONS	 						*
 ************************************************************/

const char *Span::NoSpan::what() const throw(){
	return ("Container length is either empty or too small.");
};

const char *Span::ContainerFull::what() const throw(){
	return ("Length max of Span is reached, container is full.");
};

const char *Span::ContainerTooSmall::what() const throw(){
	return ("Container capacity is too small.");
};