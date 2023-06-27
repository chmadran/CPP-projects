/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:55:32 by chmadran          #+#    #+#             */
/*   Updated: 2023/06/23 10:33:09 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string input) : ClapTrap(input) {
	this->hitPoints = 100;
	this->energyPoints = 50; 
	this->attackDamage = 20;
	std::cout << "ScavTrap " << this->name << " constructor called." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	if (this == &other)
		return *this;

	ClapTrap::operator=(other);

	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->name << " destructor called." << std::endl;
}

void ScavTrap::attack(const std::string& target){
	if (energyPoints <= 0) {
		std::cout << "ScavTrap " << this->name << " is out of energy." << std::endl;;
		return; }
	std::cout << "ScavTrap " << name << " attacks " << target;
	std::cout << " causing " << attackDamage << " points of damage"  << std::endl;
	energyPoints = energyPoints - 1;
}

void	ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->name << " has gate keeper mode activated." << std::endl;
}