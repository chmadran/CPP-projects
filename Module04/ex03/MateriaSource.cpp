/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 11:12:31 by chmadran          #+#    #+#             */
/*   Updated: 2023/06/27 11:23:47 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){
	std::cout << "MateriaSource default constructor called." << std::endl;
	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = 0;
	}
}

MateriaSource::MateriaSource(MateriaSource const & other) {
	for (int i = 0; i < 4; i++)
	{
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
	}
	std::cout << "MateriaSource copy constructor called." << std::endl;
}

MateriaSource & MateriaSource::operator=(MateriaSource const & other) {
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
	}
	std::cout << "MateriaSource assignement operator constructor called." << std::endl;
	return *this;
}

MateriaSource::~MateriaSource(){
	std::cout << "MateriaSource default destructor called." << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
}

void	MateriaSource::learnMateria(AMateria* m) {
	int i = 0;

	while ((this->_inventory)[i] != 0 && i < 4)
		i++;
	if (i >= 4)
	{
		std::cout << "Can't learn more than 4 Materia";
		return ;
	}
	(this->_inventory)[i] = m;
	std::cout << "Materia " << m->getType() << " learned\n";
}

AMateria*	MateriaSource::createMateria(std::string const & type) {
	int i = 0;

	while ((this->_inventory)[i] && ((this->_inventory)[i])->getType() != type && i < 4)
		i++;
	if (i >= 4 || !(this->_inventory)[i])
	{
		std::cout << type << " materia does not exit\n";
		return (NULL);
	}
	std::cout << "Materia " << type << " created\n";
	return (((this->_inventory)[i])->clone());
}

