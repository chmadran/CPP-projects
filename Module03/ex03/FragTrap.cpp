/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 18:21:23 by chmadran          #+#    #+#             */
/*   Updated: 2023/06/23 11:24:35 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"


FragTrap::FragTrap() : ClapTrap() {
    std::cout << "FragTrap default constructor called." << std::endl;
}

FragTrap::FragTrap(std::string input) : ClapTrap(input) {
	this->hitPoints = 100;
	this->energyPoints = 50; 
	this->attackDamage = 20;
	std::cout << "FragTrap " << this->name << " constructor called." << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	if (this == &other)
		return *this;

	ClapTrap::operator=(other);

	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << this->name << " destructor called." << std::endl;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "🖐️ [HIGH FIVE] 🖐️" << std::endl;
}