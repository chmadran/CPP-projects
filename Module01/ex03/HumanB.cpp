/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:27:01 by chmadran          #+#    #+#             */
/*   Updated: 2023/09/20 16:59:15 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name) {
	return;
}

HumanB::~HumanB (void){
	return;
}

void	HumanB::setWeapon(Weapon& weapon) {
	_weapon = &weapon;
}

void	HumanB::attack(void){
	std::cout << _name << " attacks with their ";
	std::cout << _weapon->getType() << std::endl;
}