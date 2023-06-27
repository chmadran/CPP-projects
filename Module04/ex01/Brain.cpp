/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:12:53 by chmadran          #+#    #+#             */
/*   Updated: 2023/06/26 14:31:36 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		ideas[i] = "An idea";
	std::cout << "Brain default constructor called." << std::endl;
}

Brain::Brain(Brain& rhs) {
	std::string *rhs_ideas = rhs.getIdeas();
	ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		ideas[i] = rhs_ideas[i] + " stolen";
}

Brain::~Brain() {
	delete [] (ideas);
	std::cout << "Brain default destructor called." << std::endl;
}

Brain Brain::operator=(const Brain &rhs) {
	return *this;
}

std::string *Brain::getIdeas()
{
	return ideas;
}