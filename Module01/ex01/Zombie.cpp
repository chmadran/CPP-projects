/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 10:57:04 by chmadran          #+#    #+#             */
/*   Updated: 2023/09/20 16:32:32 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( const std::string& name ){
	_name = name;
}

Zombie::~Zombie(void) {
	return;
}

void	Zombie::announce(void){
	std::cout << "BOUH Im Zombie " << _name << std::endl;
}