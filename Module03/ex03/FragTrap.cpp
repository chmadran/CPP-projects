/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 18:21:23 by chmadran          #+#    #+#             */
/*   Updated: 2023/09/26 13:15:25 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) {
	std::cout << "FragTrap " << _name;
	std::cout << " default constructor called." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << "FragTrap " << _name;
	std::cout << " string constructor called." << std::endl;
	_hitPoints = FRAG_HP;
	_energyPoints = FRAG_EP; 
	_attackDamage = FRAG_DAM;
}

FragTrap::FragTrap(const FragTrap& original) : ClapTrap(original._name) {
	std::cout << "FragTrap " << _name; 
	std::cout << " copy constructor called." << std::endl;
	_hitPoints = original._hitPoints;
	_energyPoints = original._energyPoints;
	_attackDamage = original._attackDamage;
}

FragTrap& FragTrap::operator=(const FragTrap &original) {
	if (this != &original)
	{
		_name = original._name;
		_hitPoints = original._hitPoints;
		_energyPoints = original._energyPoints;
		_attackDamage = original._attackDamage;
	}
	return (*this);
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << _name;
	std::cout << " destructor called." << std::endl;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "🖐️ [HIGH FIVE] 🖐️" << std::endl;
}