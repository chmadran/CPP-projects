/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:52:36 by chmadran          #+#    #+#             */
/*   Updated: 2023/06/23 10:10:34 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string input) : name(input), hitPoints(10), energyPoints(10), attackDamage(5) {
	std::cout << "Default constructor called." << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &rhs)
{
	*this = rhs;
	std::cout << "ClapTrap copy constructor called" << std::endl;
	return;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs) {
	if (this == &rhs)
		return *this;

	name = rhs.name;
	hitPoints = rhs.hitPoints;
	energyPoints = rhs.energyPoints;
	attackDamage = rhs.attackDamage;

	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called." << std::endl;
}

void ClapTrap::attack(const std::string& target){
	if (energyPoints <= 0) {
		std::cout << "Claptrap out of energy. " << std::endl;;
		return; }
	std::cout << "Claptrap " << name << " attacks " << target;
	std::cout << " causing " << attackDamage << " points of damage"  << std::endl;
	energyPoints = energyPoints - 1;
}

void ClapTrap::takeDamage(unsigned int amount){
	std::cout << "Claptrap " << name << " gets attacked";
	std::cout << " loosing " << amount << " points of damage." << std::endl;
	hitPoints = hitPoints - amount;
}

void ClapTrap::beRepaired(unsigned int amount){
	if (energyPoints <= 0) {
		std::cout << "Claptrap out of energy. " << std::endl;;
		return; }
	std::cout << "Claptrap repairs itself, it gets ";
	std::cout << amount << " hit points back"  << std::endl;;
	hitPoints = hitPoints + amount;
	energyPoints = energyPoints - 1;
}