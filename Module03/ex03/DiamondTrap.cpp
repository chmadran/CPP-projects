/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 18:35:04 by chmadran          #+#    #+#             */
/*   Updated: 2023/06/23 11:21:59 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
    std::cout << "DiamondTrap default constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& input) : ClapTrap(input + "_clap_name"), FragTrap(input), ScavTrap(input) {
    this->name = input;
    std::cout << "DiamondTrap constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), FragTrap(other), ScavTrap(other) {
    this->name = other.name;
    std::cout << "DiamondTrap copy constructor called." << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    if (this == &other)
        return *this;

    ClapTrap::operator=(other);
    FragTrap::operator=(other);
    ScavTrap::operator=(other);
    this->name = other.name;

    return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap destructor called." << std::endl;
}

void DiamondTrap::setName(const std::string& input) {
    this->name = input;
}

const std::string& DiamondTrap::getName() const {
    return this->name;
}
