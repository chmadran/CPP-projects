/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 10:27:31 by chmadran          #+#    #+#             */
/*   Updated: 2023/09/20 16:19:06 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Zombie.hpp"

Zombie::Zombie(const std::string& name) {
	_name = name;
}

Zombie::~Zombie( void ) {
	std::cout << "Destructor called for " << _name << std::endl;
	return;
}

void	Zombie::announce( void ){
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}