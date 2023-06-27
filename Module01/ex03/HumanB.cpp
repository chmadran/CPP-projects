/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:27:01 by chmadran          #+#    #+#             */
/*   Updated: 2023/06/21 12:58:57 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weaponPtr(nullptr) {
	return;
}

HumanB::~HumanB ( void ){
	return;
}

void	HumanB::setWeapon(Weapon& weapon) {
    weaponPtr = &weapon;
}

void	HumanB::attack( void ){
	std::string weaponType = weaponPtr->getType();
	std::cout << name << " attacks with their " << weaponType << std::endl;
}