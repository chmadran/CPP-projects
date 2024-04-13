/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:55:32 by chmadran          #+#    #+#             */
/*   Updated: 2023/09/26 12:16:59 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap() {
	std::cout << "ScavTrap " << _name << " constructor called." << std::endl;
	_hitPoints = SCAV_HP;
	_energyPoints = SCAV_EP;
	_attackDamage = SCAV_DAM;
}


ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "ScavTrap " << _name << " string constructor called." << std::endl;
	_hitPoints = SCAV_HP;
	_energyPoints = SCAV_EP;
	_attackDamage = SCAV_DAM;
}

ScavTrap::ScavTrap(const ScavTrap &original) : ClapTrap (original._name) {
	std::cout << "ScavTrap " << _name << " copy constructor called." << std::endl;
	_hitPoints = original._hitPoints;
	_energyPoints = original._energyPoints;
	_attackDamage = original._attackDamage;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap " << _name << " destructor called." << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& original) {
	if (this != &original)
	{
		_name = original._name;
		_hitPoints = original._hitPoints;
		_energyPoints = original._energyPoints;
		_attackDamage = original._attackDamage;
	}
	return (*this);
}

void ScavTrap::attack(const std::string& target)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		std::cout << "ScavTrap " << _name;
		std::cout << " attacks " << target;
		std::cout << " causing " << _attackDamage;
		std::cout << " points of damage"  << std::endl;
		_energyPoints--;
	}
	else if (_energyPoints > 0)
	{
		std::cout << "ScavTrap " << _name;
		std::cout << " has no more hit points." << std::endl;
	}
	else if (_hitPoints > 0)
	{
		std::cout << "ScavTrap " << _name;
		std::cout << " has ran out of energy." << std::endl;
	}
}

void	ScavTrap::guardGate(void) {
	std::cout << "ScavTrap " << _name;
	std::cout  << " has entered gate keeper mode." << std::endl;
}