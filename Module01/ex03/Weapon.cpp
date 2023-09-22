/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:27:09 by chmadran          #+#    #+#             */
/*   Updated: 2023/09/20 16:56:59 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"

Weapon::Weapon (std::string type) {
	setType(type);
}

Weapon::~Weapon (void){
	return;
}

void	Weapon::setType(std::string newType){
	_type = newType;
}

const std::string& Weapon::getType(void) const {
	return (_type);
}