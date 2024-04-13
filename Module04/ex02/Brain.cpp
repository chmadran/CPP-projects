/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:12:53 by chmadran          #+#    #+#             */
/*   Updated: 2023/09/26 17:43:54 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) {
	_nbIdeas = 0;
	std::cout << "Brain default constructor called." << std::endl;
}

Brain::Brain(const Brain& original) {
	_nbIdeas = original._nbIdeas;
	for (int i = 0; i < _nbIdeas; i++)
		_ideas[i] = original._ideas[i];
	std::cout << "Brain copy constructor called." << std::endl;
}

Brain::~Brain(void) {
	std::cout << "Brain destructor called." << std::endl;
}

Brain Brain::operator=(const Brain &original) {
	if (this != &original)
	{
		_nbIdeas = original._nbIdeas;
		for (int i = 0; i < _nbIdeas; i++)
			_ideas[i] = original._ideas[i];
	}
	return (*this);
}

void	Brain::addIdea(std::string idea){
	_ideas[_nbIdeas % 100] = idea;
	_nbIdeas++;
}

void	Brain::printIdea(void) const{
	if (_nbIdeas == 0)
		std::cout << "There is not a single idea in this brain" << std::endl;
	for (int i = 0; i < _nbIdeas; i++)
		std::cout << _ideas[i] << std::endl;
}

int	Brain::getnbIdeas(void) const {
	return (_nbIdeas);
}