/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 10:48:06 by chmadran          #+#    #+#             */
/*   Updated: 2023/06/27 11:33:06 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(){
	std::cout << "Character default constructor called." << std::endl;
}

Character::Character(std::string name) : _name(name) {
	std::cout << "Character named " << _name <<  " has been created." << std::endl;
	for(int i = 0; i < 4; i++)
	{
		_inventory[i] = 0;
	}
}

Character::Character(Character const & ref){
	std::cout << "Character copy constructor called." << std::endl;

	for(int i = 0; i < 4; i++)
	{
		if ((ref._inventory)[i])
			(_inventory)[i] = (ref._inventory[i])->clone();
	}
}

Character & Character::operator=(Character const & ref) {
	std::cout << "character operator assignement constructor called." << std::endl;
	for(int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
		if (ref._inventory[i])
			_inventory[i] = (ref._inventory[i])->clone();
	}
	return (*this);
}

Character::~Character(){
	std::cout << "character " << _name << "destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
}

std::string const & Character::getName() const {
	return _name;
}

AMateria	*Character::getMateriaFromInventory(int idx)
{
	return (_inventory)[idx];
}

void Character::equip(AMateria* m)
{
	int i = 0;

	if (!m)
	{
		std::cout << _name << " tried to equip nothing and it did nothing\n";
		return ;
	}
	while ((_inventory)[i] != 0 && i < 4)
		i++;
	if (i >= 4)
	{
		std::cout << _name << " can't equip more than 4 Materia";
		return ;
	}
	(_inventory)[i] = m;
	std::cout << _name << " equipped materia " << m->getType() << " in slot " << i << "\n";
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
		std::cout << _name << " tried to unequip nothing at slot " << idx << " and it did nothing\n";
	else if (!(_inventory)[idx])
		std::cout << _name << " has nothing equipped at slot " << idx << " so he can't unequip it\n";
	else
	{
		AMateria *ptr = (_inventory)[idx];
		std::cout << _name << " unequipped " << ptr->getType() << " at slot "<< idx << "\n";
		(_inventory)[idx] = 0;
	}
}

void Character::use(int idx, ICharacter& target)
{
	std::string	name = this->getName();

	if (idx < 0 || idx >= 4 || !(this->_inventory)[idx])
	{
		std::cout << "Nothing found to use at index " << idx << std::endl;
		return ;
	}
	std::cout << name;
	((_inventory)[idx])->use(target);
}