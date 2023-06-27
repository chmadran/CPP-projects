/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:26:56 by chmadran          #+#    #+#             */
/*   Updated: 2023/06/21 12:17:00 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA (std::string name, Weapon weapon) : name(name), weapon(weapon) {
	return;
}

HumanA::~HumanA ( void ){
	return;
}

void	HumanA::attack( void ){
	std::string weaponType = weapon.getType();
	std::cout << name << " attacks with their " << weaponType << std::endl;
}