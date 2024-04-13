/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 18:35:04 by chmadran          #+#    #+#             */
/*   Updated: 2023/09/26 14:15:42 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap("CLAPNAME") {
	_name = "Diamond";
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap " << _name;
	std::cout << " default constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name + "_clap_name") {
	_name = name;
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap " << _name;
	std::cout << " string constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &original) : ClapTrap(original._name) {
	_name = original._name;
	_hitPoints = original._hitPoints;
	_energyPoints = original._energyPoints;
	_attackDamage = original._attackDamage;
	std::cout << "DiamondTrap " << _name;
	std::cout << " copy constructor called." << std::endl;
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << "DiamondTrap" << _name;
	std::cout << " destructor called." << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& original) {
	if (this != &original)
	{
		_name = original._name;
		_hitPoints = original._hitPoints;
		_energyPoints = original._energyPoints;
		_attackDamage = original._attackDamage;
	}
	return (*this);
}

void	DiamondTrap::attack(const std::string& target){
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void) {
	std::cout << "Hi, my name is " << _name << std::endl;
	std::cout << "My ClapTrap name is " << ClapTrap::_name << std::endl;
}
