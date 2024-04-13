/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:52:36 by chmadran          #+#    #+#             */
/*   Updated: 2023/09/26 14:07:07 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("ClapTrap"), _hitPoints(HPMAX), _energyPoints(EPMAX), _attackDamage(ADAMAGE) {
	std::cout << "Default constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(HPMAX), _energyPoints(EPMAX), _attackDamage(ADAMAGE) {
	std::cout << "ClapTrap " << _name;
	std::cout << " string constructor called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &original)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = original;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "Default destructor called." << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& original) {
	if (this != &original)
	{
		_name = original._name;
		_hitPoints = original._hitPoints;
		_energyPoints = original._energyPoints;
		_attackDamage = original._attackDamage;
	}
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		std::cout << "Claptrap " << _name;
		std::cout << " attacks " << target;
		std::cout << " causing " << _attackDamage;
		std::cout << " points of damage"  << std::endl;
		_energyPoints--;
	}
	else if (_energyPoints > 0)
	{
		std::cout << "Claptrap " << _name;
		std::cout << " has no more hit points." << std::endl;
	}
	else if (_hitPoints > 0)
	{
		std::cout << "Claptrap " << _name;
		std::cout << " has ran out of energy." << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints > 0)
	{
		std::cout << "Claptrap " << _name << " gets attacked";
		std::cout << " loosing " << amount << " hitPoints." << std::endl;
		_hitPoints = _hitPoints - amount;
	}
	else if (_hitPoints <= 0)
	{
		std::cout << "Claptrap " << _name; 
		std::cout << " has no more hitPoints." << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints > 0)
	{
		std::cout << "Claptrap " << _name;
		std::cout << " repairs itself by " << amount;
		std::cout << " HP." << std::endl;
		_energyPoints--;
		_hitPoints += amount;
	}
	else if (_energyPoints <= 0)
	{
		std::cout << "Claptrap " << _name;
		std::cout << " has no more energyPoints." << std::endl;
	}
}