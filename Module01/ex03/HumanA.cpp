/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:26:56 by chmadran          #+#    #+#             */
/*   Updated: 2023/09/20 16:57:17 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA (std::string name, Weapon& weapon) : _name(name), _weapon(weapon) {
	return;
}

HumanA::~HumanA (void) {
	return;
}

void	HumanA::attack(void) {
	std::cout << _name << " attacks with their ";
	std::cout << _weapon.getType() << std::endl;
}